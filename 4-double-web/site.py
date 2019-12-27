import string
import urllib2
from bottle import route, run, post, get, request

@get('/')
def index():
    with open(__file__) as f:
        return '<pre>' + "".join({'<':'<','>':'>'}.get(c,c) for c in f.read()) + '</pre>'

@get('/flag')
def test():
    return 'flag'

@post('/isup')
@get('/isup')
def isup():
    try:
        name = request.params.get('name', None)
        ip = request.environ.get('REMOTE_ADDR')
        print("ip", ip)
        is_remote = not (ip.startswith('127') or ip.startswith('172'))

        valids = [x in name for x in ['http', 'kuchenblech']]
        is_valid = all(valids)
        if is_remote and not is_valid:
            raise Exception
        print("connecting to  ", name)
        result = urllib2.urlopen(name).read()
        return result
    except Exception as e:
        return 'Error ' + name  + ' ' + str(valids) + ' ' + str(e)

run(host='0.0.0.0', port=8080, reloader=False)
