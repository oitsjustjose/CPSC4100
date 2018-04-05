import os

def clear():
	os.system('cls' if os.name == 'nt' else 'clear')


def print_sameline(to_print):
	print(to_print, end='', flush=True)


def print_err(cmd):
	print("Command: {} not found".format(cmd))


def draw_filled_box(w, h):
	# Draw the filled box:
	for i in range(h):
		for j in range(w):
			print_sameline('*')
		print("")


def draw_empty_box(w, h):
	# Draw the box:
	for i in range(h):
		# If it's the top or bottom:
		if i == 0 or i == h - 1:
			for j in range(w):
				print_sameline('*')
		# It's not the top or bottom:
		else:
			for j in range(w):
				if j == 0 or j == w - 1:
					print_sameline('*')
				else:
					print_sameline(" ")
		print("")


def draw_diagonal(size, dir):
	if "right" in dir:
		i = 0
		while i < size:
			j = size
			while j >= 0:
				if i == j:
					print_sameline('/')
				else:
					print_sameline(" ")
				j -= 1
			print("")
			i += 1
	else:
		for i in range(size):
			for j in range(size):
				if i == j:
					print_sameline('\\')
				else:
					print_sameline(" ")
			print("")


def draw_vertical(size):
	for i in range(size):
			print("|")


def draw_horizontal(size):
	# Print them (and a newline):
	for i in range(size):
			print_sameline("-")
	print("")


def main():
	clear()
	file = open(input("File for instructions:"), "r")
	for cmd in file.readlines():
		parts = cmd.lower().replace(" ", "").split(",")
		# Expecting draw_horizontal_line, size
		if "draw_horizontal_line" in parts[0] and len(parts) == 2:
			draw_horizontal(int(parts[1]))
		# Expecting draw_vertical_line, size
		elif "draw_vertical_line" in parts[0] and len(parts) == 2:
			draw_vertical(int(parts[1]))
		# Expecting draw_horizontal_line, size, dir
		elif "draw_horizontal_line" in parts[0] and len(parts) == 3:
			draw_horizontal(int(parts[1]), parts[2])
		# Expecting draw_empty_box, w, h
		elif "draw_empty_box" in parts[0] and len(parts) == 3:
			draw_empty_box(int(parts[1]), int(parts[2]))
		# Expecting draw_filled_box, w, h
		elif "draw_filled_box" in parts[0] and len(parts) == 3:
			draw_filled_box(int(parts[1]), int(parts[2]))
		else:
			print_err(cmd)


if __name__ == "__main__":
	main()

