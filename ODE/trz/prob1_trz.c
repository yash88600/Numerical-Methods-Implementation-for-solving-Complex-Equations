#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void trz(
   double t_old,
   double x_old,
   double h,
   double *x_new
) {
   double tolr,x,f,delx,t_new,dfdx;
   int i_NR,N;
   bool flag_done;

   N = 50;
   flag_done = false;
   x = x_old;
   t_new = t_old + h;
   tolr = 1.0e-10;

   for (i_NR=0; i_NR < N; i_NR++) {
     f = ((x - x_old)/h) + 0.5*(((x_old/2)+(6*t_old*exp(-t_old/2))) + ((x/2)+(6*t_new*exp(-t_new/2))));

     printf("%2d %13.6e\n",i_NR,f);
     if (fabs(f) < tolr) {
       *x_new = x;
       flag_done = true;
       break;
     }

    //  dfdx = (1.0/h) + 3*t_new*exp(t_new/2) - (x/2); 
    dfdx = (1.0/h) + 0.25;
     if (fabs(dfdx) < 1.0e-20) {
       printf("dfdx too small. Halting...\n");
       exit(0);
     }
     delx = -f/dfdx;

     x += delx;
   }
   if (!flag_done) {
     printf("NR did not converge. Halting...\n");
     exit(0);
   }
   return;
}

int main()

{
    double x,t,x_new,t_end,f;
    FILE *fp1;
    double h[] = {0.05, 0.1, 0.5, 0.8};
    char name[10];
    for(int i=0; i < 4; i++)
    {
        snprintf(name, 10, "trz_%d.dat", i);
        fp1 = fopen(name, "w");
        x = 2.0;
        t = 0.0;
        t_end = 20.0;

        fprintf(fp1,"%13.6e %13.6e\n", t,x);

        while (t < t_end) {
            trz(t,x,h[i],&x_new);

            t += h[i];

            fprintf(fp1,"%13.6e %13.6e\n", t,x_new);

            x = x_new;
        }
        fclose(fp1);
    }
   return 0;
}
