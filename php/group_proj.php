<?php
$grid = array();

//creates the grid.
for($i = 0; $i < 32; $i++){
	$grid[$i] = array();
	for($r = 0; $r < 32; $r++){
		$grid[$i][$r] = " ";
	}
}

//Writes ASCII output to the file.
function print_grid(){
	$artFile = fopen("Output.txt", "w") or die("Unable to open file!");
	global $grid;
	//Used to keep everything in line.
	print("\n");
	for($i = 0; $i < count($grid); $i++){
		foreach($grid[$i] as $key => $val){
		print($val);
		fwrite($artFile, $val);	
		}
	print("\n");
	fwrite($artFile, "\n");
	}
	fclose($artFile);
}

//done
function draw_filled_box($x, $y, $w, $h){
	global $grid;
	
	//No Op Cases
	if($x < 0 || $y < 0 || $w < 1 || $h < 1){
		return "Invalid Input";
	}
	if( $y > count($grid) || $x > count($grid[0]) || ($y + $w) > count($grid) || ($x + $h)  > count($grid[0])){
		return "Invalid Input";
	}
	
	//box creation
	for($i = 0; $i < $h; $i++){
		for($j = 0; $j < $w; $j++){
			$grid[$y + $j][$x + $i] = "#";
		}
	}
}

//done
function draw_empty_box($x, $y, $w, $h){
	global $grid;
	
	//No Op Cases
	if( $x < 0 || $y < 0 || $w < 1 || $h < 1){
		return "Invalid Input";
	}
	
	if( $y > count($grid) || $x > count($grid[0]) || ($y + $w) > count($grid) || ($x + $h)  > count($grid[0])){
		return "Invalid Input";
	}
	
	//Box creation
	for($i = 0; $i < $h; $i++){
		for($j = 0; $j < $w; $j++){
				if($i == 0 || $i == $h - 1){
					$grid[$y + $j][$x + $i] = "#";
				}
				else if($j == 0 || $j == $w - 1){
					$grid[$y + $j][$x + $i] = "#";
				}
		}
		echo " ";
	}
}

//done
function draw_diagonal($x, $y, $l, $dir){
	global $grid;
	
	//No Op Case
	if($x < 1 || $y < 1 || $l < 1 || $y + $l > count($grid) || $x + $l > count($grid[0])){
		return "Invalid Input";
	}
	
	//Diagonal line creation
	if($dir == "right"){
		$i = 0;
		while($i < $l){
			$j = $l;
			while($j >= 0){
				if($i == $j){
					$grid[$y + $j][$x - $i] = "/";
				}
				$j -= 1;
			}
			$i += 1;
		}
	} else {
		for($i = 0; $i < $l; $i++){
			for($j = 0; $j < $l; $j++){
				if($i == $j){
					$grid[$y + $j][$x + $i] = "\\";
				}
			}
		}
	}
}

//done
function draw_vertical($x, $y, $l){
	global $grid;
	
	//No Op Case
	if($x < 1 || $y < 1 || $l < 1 || $y + $l > count($grid)){
		return "Invalid Input";
	}
	
	//Vertical line creation
	for($i =0; $i < $l; $i++){
		$grid[$y + $i][$x] = "|";
	}
}

//done
function draw_horizontal($x, $y, $l){
	global $grid;
	
	//No Op Case
	if($x < 1 || $y < 1 || $l < 1 || $y + $l > count($grid)){
		return "Invalid Input";
	}
	
	//Horizontal line creation
	for($i =0; $i < $l; $i++){
		$grid[$y][$x + $i] = "-";
	}
}

//done
function fill($x, $y, $string){
	global $grid;
	
	$filler = substr($string, 0, 1);
	
	//No Op Case
	if($x < 1 || $y < 1){
		return " ";
	}
	
	if($grid[$y][$x] == " "){
		$grid[$y][$x] = $filler;
		//north
		if($grid[$y + 1][$x] == " "){
			fill($x, $y + 1, $filler);
		}
		//south
		if($grid[$y - 1][$x] == " "){
			fill($x, $y - 1, $filler);
		}
		//east
		if($grid[$y][$x + 1] == " "){
			fill($x + 1, $y, $filler);
		}
		//west
		if($grid[$y][$x - 1] == " "){
			fill($x - 1, $y, $filler);
		}
	}
}

//Test Cases

//draw_filled_box(28, 0, 4, 4);

draw_empty_box(0, 0, 4, 4); 
draw_diagonal(16, 8, 7, "right");
draw_diagonal(17, 8, 7, "left");
draw_horizontal(9, 15, 16);
draw_vertical(7, 7, 16);
draw_vertical(26, 7, 16);
//fill(2, 2, "@#$%^&");
//fill(6, 6, "@#$%^&");
fill(16, 13, "@#$%^&");
print_grid();
?>