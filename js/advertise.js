function CloseDiv(div) {
	document.getElementById(div).style.display = 'none';
};
function getScroll(){
          return {
              left: window.pageXOffset || document.documentElement.scrollLeft || document.body.scrollLeft || 0,
              top: window.pageYOffset || document.documentElement.scrollTop || document.body.scrollTop || 0
          };
      };

var box = document.getElementById('goodsDiv');
var topNavad = document.getElementById('goodsAdv');
var intervalSed, x = -1,
	y = -1,
intervalSed = setInterval(moves, 8);
var dif=0;
topNavad.onmouseover = function() {
	clearInterval(intervalSed);
};
topNavad.onmouseout = function() {
	intervalSed = setInterval(moves, 8);
};
function moves() {
	if (topNavad.offsetLeft >= box.offsetWidth - topNavad.offsetWidth || topNavad.offsetLeft <= 0) {
		x = -x;
	}
	if (topNavad.offsetTop >= screen.availHeight-170 - topNavad.offsetHeight +getScroll().top|| topNavad.offsetTop <=getScroll().top ) {
		y = -y;
	}
	topNavad.style.top = topNavad.offsetTop + y+ "px";
	topNavad.style.left = topNavad.offsetLeft + x + "px";
	if(dif!=getScroll().top){
		topNavad.style.top=topNavad.offsetTop +getScroll().top-dif+'px';
		dif=getScroll().top;
	}
	console.log(getScroll().top);
};
