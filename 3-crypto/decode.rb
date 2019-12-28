require 'bigdecimal'

# message = int('REDACTED', base=35)
N = 31882864753733457706900355195561745936205728163688545344755624355885302677527509480805991969514641856022311950710014654686332759895303124949904557581766107448945073828773339824936328117599459705430379854436444155104737774883908742430619368768337640156577480749932446289330171110268995901030116001751822218657
# c = message^3 % N
c = 272712645051843502864020676686837219546440933810920336253597504130258033336636323130656292878088405243095416128

def print_message(m)
  m2 = m
  (32...97).each do |i|
    message = ""
    message2 = ""
    m = m2
    while m != 0
      b = m % 35
      m /= 35
      # print(b.class, b)
      c = b + i
      message = c.to_i.chr + message
      message2 =  message2 + c.to_i.chr
    end
    puts message
    puts message2
  end
end

def root(a,b)
  return b if b<2
  a1, c = a-1, 1
  f = -> x {(a1*x+b/(x**a1))/a}  # a lambda with argument x
  d = f[c]
  e = f[d]
  c, d, e = d, e, f[e] until [d,e].include?(c)
  [d,e].min
end


c_3 = c
i = 0
loop do
  #m =(c_3)**(1/3.0)
  m = root(3, c_3)
  error = m**3 - c_3
  is_whole = error ==0
  i += 1
  if is_whole
    STDOUT.print("works! "  + i.to_s + "\n") # + " " + cubic_root.to_s + " " + c_3.to_s +  "\r")
    print_message(m.to_i)
    break
  end

  STDOUT.print(error.to_s + "\n") # + " " + cubic_root.to_s + " " + c_3.to_s +  "\r")
  STDOUT.flush
  c_3 = c_3 + N
end
