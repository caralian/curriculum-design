// function getScroll() {
// 	return {
// 		left: window.pageXOffset || document.documentElement.scrollLeft || document.body.scrollLeft || 0,
// 		top: window.pageYOffset || document.documentElement.scrollTop || document.body.scrollTop || 0
// 	};
// }

// var sTop = getScroll().top;
// console.log(div.scrollTop);


window.onload = function() {
	var box = document.getElementById('goodsIntr');
	var pic = document.getElementById('intrPic');
	var top = document.getElementById('intrTop');
	var bottom = document.getElementById('intrBottom');
	var intervalId, num = 0;
	top.onmouseover = function() {
		clearInterval(intervalId);

		intervalId = setInterval(function() {
			if (num > -5230) {
				num -= 10;
				pic.style.top = num + "px";
			}

		}, 20);

	};
	top.onmouseout = function() {
		clearInterval(intervalId);
	}
	bottom.onmouseover = function() {
		clearInterval(intervalId);

		intervalId = setInterval(function() {
			if (num < 0) {
				num += 10;
				pic.style.top = num + "px";
			}

		}, 20);
	};
	bottom.onmouseout = function() {
		clearInterval(intervalId);
	};

}
