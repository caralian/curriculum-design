var txt_num = document.getElementById("buy_num");

function add() {
	txt_num.value = parseInt(txt_num.value) + 1;
	// console.log(txt_num.value);
}

function reduce() {
	if(txt_num.value>1)
		txt_num.value = parseInt(txt_num.value) - 1;
	// console.log(txt_num.value);
}
