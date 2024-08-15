ques 2
contains 3 images representing the plot of the 3 functions along with the roots.

(i) 	𝑓(𝑥) ≡ 2𝑥3 + 5𝑥2 − 22𝑥 + 15 = 0, 𝑥0 = −10 	=> optimal value obtained is -5.000
(ii) 	𝑓(𝑥) ≡ 2𝑥3 + 5𝑥2 − 22𝑥 + 15 = 0, 𝑥0 = 0	=> optimal value obtained is  1.000
(iii) 	𝑓(𝑥) ≡ cos 𝑥 − 𝑒−𝑥/2 = 0, 𝑥0 = 1		=> optimal value obtained is  0.864439
(iv)		 𝑓(𝑥) ≡ tan−1 𝑥 = 0, 𝑥0 = 0.5						=> optimal value obtained is  0.000000
(v)  	 𝑓(𝑥) ≡ tan−1 𝑥 = 0, 𝑥0 = 1.5						=> optimal value obtained is  0.00000



"Usage: <function index> <initial_guess> <iterations> <tollerance> <damping_factor>"

enter the function index 
0 for func - 2x3 + 5x2 - 22x + 15
1 for cos x - e(-x/2)
2 for tan-1(x)

exmaple cmd command:
cd "c:\Users\YASH\Desktop\Mtech stuff\Sem 2\computational techniques EE-774\newton raphson code\lab2 codes\prob 2\" ; if ($?) { gcc prob2.c -o prob2 } ; if ($?) { .\prob2 2 1.5 50 10e-12 0.9}

