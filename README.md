# Secant-and-Bisection-Methods
finding root of polinomials with secant and bisection methods using cpp\

This project is written in C++ and needs a C++ compiler.\
In this project at least (n+1) + 3 (where n >= 0) arguements are needed in order:\
an, an-1,...a0, x0, x1, tolerance (where x1 > x0)\
an, an-1,...a0 are coefficients of the polinamial with degree n\
This Porject aims to get the root of the polinomial f(x) = an*x^n + ... + a0 in [x0,x1] interval\
using tolerance value\

it finds the necessary iteration counts and the roots for 3 methods\
1 bisection method\
2 secant method\
3 a hybrid method which is started by iterating it using bisection method 2 times and iterating \
the result using secant method until it finds the answer\

Example input and output\
for (in powershell)\
	./main.exe -6 -2 2 -4 -2 6 9 0.8 1.5 0.0001\
we get\
	Using bisection\
	X = 1.0549\
	Count = 13\
	Using secant\
	X = 1.05496\
	Count = 8\
	Using hybrid\
	X = 1.05496\
	Count = 7\
where X is root and Count is number of iterations\
