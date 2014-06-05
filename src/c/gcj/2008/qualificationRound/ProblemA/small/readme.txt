link to the problem: https://code.google.com/codejam/contest/32013/dashboard

Problem faced:
how to read strings with spaces in C.

Solution:
useing fgets

Problem faced:
last string gets lot of garbage value.

Solution:
It is due to bad position of file pointer after a fscanf.
make a dummy fscanf call to get the \n character
