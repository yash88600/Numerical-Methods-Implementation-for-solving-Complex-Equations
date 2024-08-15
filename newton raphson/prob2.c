#include <stdio.h>
#include <math.h>


float func1(float x)
{
    return 2*x*x*x + 5*x*x - 22*x + 15;
}

float funcdash1(float x)
{
    return 6*x*x + 10*x -22;
}

float func2(float x)
{
    return cos(x) - exp(-x/2);
}
float funcdash2(float x)
{
    return -sin(x) - (-1/2)*exp(-x/2);
}

float func3(float x)
{
    return atan(x);
}

float funcdash3(float x)
{
    return 1/(1 + x*x);
}
int main(int argc, char* argv[]) {
        printf("enter the index \n0 for func - 2x3 + 5x2 - 22x + 15,\n 1 for cos x - e-x/2,\n 2 for tan-1 x : \n");
    	if (argc < 6) {
		printf("Usage: <function index> <initial_guess> <iterations> <tollerance> <damping_factor>\n");
		return 1;
	    }
        int index;
    	float x0;
        int iter;
        float tol;
        float damp;

        sscanf(argv[1], "%d", &index);
        sscanf(argv[2], "%f", &x0);
        sscanf(argv[3], "%d", &iter);
        sscanf(argv[4], "%f", &tol);
        sscanf(argv[5], "%f", &damp);
        printf("entered data is as follow \n index is %d, \ninitial guess is %f, \niteration is %d, \ntolerance is %f, \ndamping is %f\n", index, x0, iter, tol, damp);
        switch (index)
        {
        case 0:
        {
            printf("Initial guess: %lf, func(x0) = %lf\n", x0, func1(x0));
            for (int i = 0; (i < iter && fabs(func1(x0)) > tol); i++) 
            {
                float fval = func1(x0);
                float fdashval = funcdash1(x0);
                x0 = x0 - damp*(fval / fdashval);
                printf("%d: New x0 = %f, f(x0) = %f\n", i+1, x0, func1(x0));
        
            }
        }
        break;
        case 1:
        {
            printf("Initial guess: %lf, func(x0) = %lf\n", x0, func2(x0));
            for (int i = 0; (i < iter && fabs(func2(x0)) > tol); i++) 
            {
                float fval = func2(x0);
                float fdashval = funcdash2(x0);
                x0 = x0 - damp*(fval / fdashval);
                printf("%d: New x0 = %f, f(x0) = %f\n", i+1, x0, func2(x0));
        
            }
        }
        break;
        case 2:
        {
            printf("Initial guess: %lf, func(x0) = %lf\n", x0, func3(x0));
            for (int i = 0; (i < iter && fabs(func3(x0)) > tol); i++) 
            {
                float fval = func3(x0);
                float fdashval = funcdash3(x0);
                x0 = x0 - damp*(fval / fdashval);
                printf("%d: New x0 = %f, f(x0) = %f\n", i+1, x0, func3(x0));
        
            }
        }
        break;     
        default:
            break;
        }
    return 0;
}