const fs = require('fs');

fs.readFile('code.js', {encoding: 'utf-8'}, function(err,data){
    if (!err) {
        console.log('http://199.247.22.71:8075/?code=' + encodeURIComponent(data))
    } else {
        console.log(err);
    }
});
