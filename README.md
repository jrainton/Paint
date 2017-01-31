# Paint
A basic Paint copy using C.

type in:
h - help
q - quit
w [row_start] [col_start] [row_end] [col_end] - to draw a line from (row_start,col_start) to (row_end,col_end)
r [num_rows] [num_cols] - resizes the board to the desired length and height
a [r | c] [pos] - adds another row or column at the desired slot Ex. a r 3 would add a row to position 3 on the board
d [r | c] [pos] - deletes a row or column at the desired slot Ex. d c 4 would delete the column at position 4 on the board
e [row] [col] - gets rid of a point at the desired location
s [file_name] - saves the board to a file called file_name
l [file_name] - loads a board that was saved
