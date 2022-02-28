var small_pic = document.getElementById("picImg");
var goodsPic = document.getElementById("goodsPic");
var float = document.getElementById("picMagn");
var big_img = document.getElementById("picBig");
var span=document.getElementById("picThum");
var dots = document.getElementsByTagName("span");
var arrow=document.querySelector(".picArrow");
var arrow_right = document.querySelector(".arrow_right");
var arrow_left = document.querySelector(".arrow_left");
var intervalFir;
var index = 6;
var dis = 0;
var r=1;
small_pic.onmouseover = function() {
	float.style.display = 'block';
	picDiv3.style.display = 'block';
}
autoPlay();
goodsPic.onmouseover=function(){
	clearInterval(intervalFir);
}
goodsPic.onmouseout=function(){
	autoPlay();
}
small_pic.onmouseout = function() {
	float.style.display = 'none';
	picDiv3.style.display = 'none';
}
function autoPlay(){
	showCurrentDot();
	intervalFir=setInterval(function(){
		next_pic();
		showCurrentDot();
	},1000);
}
small_pic.onmousemove = function(e) {
	var e = e || window.event;
	var x = e.clientX - 270;
	var y = e.clientY - 170;
	if (x < 0) x = 0;
	else if (x > 200) x = 200;
	if (y < 0) y = 0;
	else if (y > 200) y = 200;
	float.style.left = (index) * 400 -2400+ x+ 'px';
	float.style.top = y + 'px';
	big_img.style.left = (-index) * 800+4800 - 2 * x + 'px';
	big_img.style.top = -2 * y + 'px';
}
function showCurrentDot(){
	for(var i=6,len=10;i<len;i++){
		dots[i].className="";
	}
	dots[index].className="on"
	if(index==8&&r==1){
		r=0;
		span.style.left=-110+'px';
	}
	if(index==6&&r==0){
		r=1;
		span.style.left=0+'px';
	}
}
function next_pic(){
	index++;
	if(index<10){
		small_pic.style.left=parseInt(small_pic.style.left)-400+'px';
	} 
	if(index==10){
		index=6;
		small_pic.style.left=0+'px';
	}
}
	for (var i = 6, len = 10; i < len; i++) {
		(function(i) {
			dots[i].onmouseover = function() {
				dis = index - i;
				small_pic.style.left = (dis - index) * 400+2400 + 'px';
				dots[index].className = "";
				dots[i].className = "on";
				index = i;
				console.log(index);
			}
		})(i);
	}


arrow_left.onmouseover=function(){
	arrow_left.style.color="#000";
}
arrow_left.onmouseout=function(){
	arrow_left.style.color="#CCCCCC";
}
arrow_right.onmouseover=function(){
	arrow_right.style.color="#000";
}
arrow_right.onmouseout=function(){
	arrow_right.style.color="#CCCCCC";
}
arrow_left.onclick=function(){
	if(r==0){
	 span.style.left=0+'px';
	 r=1;
	}
}
arrow_right.onclick=function(){
	if(r==1){
		span.style.left=-110+'px';
		r=0;
	}
}
