def escape text
   text.gsub(/((?<m>\\)(?!c))|(?<m>")/, "\\\\\\k<m>").gsub(/\n/, "\\n")
end

def split_arg text, sp
   text.split(sp, 2).map {|s| s.strip}
end

def single_line outf, out, set
   outf.write "\"#{out}\" = \"#{escape set}\";\n"
end

def comment outf, arg
   outf.write "\n//#{arg}\n"
end

def buf_lines outf, type, buf
   buf.pop if buf.last.chomp.empty?
   case type
   when :just
      outf.write(buf.each.with_index.inject("") do |sum, (s, i)|
         if i < buf.size-1 then sum + "   \"#{escape s.chomp}\\n\"\n"
         else                   sum + "   \"#{escape s.chomp}\";\n" end
      end)
   when :conc
      buf = [*buf, "\n"].each_cons(2).map do |s, n|
            if s == "\n" then "\n\n"
         elsif n == "\n" then s.chomp
         else                 s.chomp + " " end
      end
      outf.write(buf.each.with_index.inject("") do |sum, (s, i)|
         if i < buf.size-1 then sum + "   \"#{escape s}\"\n"
         else                   sum + "   \"#{escape s.chomp}\";\n" end
      end)
   end
end

def parse_file outf, fp
   wr, buf = nil, nil
   for ln in fp
      type, arg = ln[0..1], ln.chomp[2..-1]
      case type
      when "##"
         buf_lines outf, wr, buf and wr = nil if wr
         comment outf, arg
      when "=="
         buf_lines outf, wr, buf and wr = nil if wr
         out, set = split_arg arg, "|"
         single_line outf, out, set
      when "%%"
         buf_lines outf, wr, buf if wr
         wr, buf = :just, []
         outf.write "\"#{arg.strip}\" =\n"
      when "@@"
         buf_lines outf, wr, buf if wr
         wr, buf = :conc, []
         outf.write "\"#{arg.strip}\" =\n"
      else
         buf << ln if wr
      end
   end
   buf_lines outf, wr, buf if wr
end

def procdir outf, type, arg
   case type
   when "comment"
      comment outf, " " + arg
   when "put data"
      set, out = split_arg arg, "->"
      single_line outf, out, set
   when "put file"
      fnam, out = split_arg arg, "->"
      outf.write "\"#{out}\" =\n"
      buf_lines outf, :just, open(fnam, "rt").read.chomp.lines
   when "parse file"
      parse_file outf, open(arg, "rt")
   end
   return outf
end

def procfdr outf, type, arg
   case type
   when "in"
      outf = open("../../#{arg}", "wb")
      outf.write "// This file was generated by compilefs.\n" +
                 "// Edit only if you aren't going to recompile.\n" +
                 "[enu default]\n\n"
   when "include"
      run_file open(arg, "rt"), outf
   end
   return outf
end

def run_file fp, outf = nil
   for ln in fp
      if (type, arg = split_arg ln, ":") and arg then
         outf = procdir outf, type, arg
      elsif (type, arg = split_arg ln, " ") and arg then
         outf = procfdr outf, type, arg
      end
   end
end

run_file open("dir.txt", "rt")

## EOF
