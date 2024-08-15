#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>



int main()
{
    double x = 2;
    double t = 0;
    double tend = 20;
    double h[] = {0.05, 0.1, 0.5, 0.8};
    double f;
    char name[10];
    FILE *fp1;
    for(int i=0; i < 4; i++)
    {
        snprintf(name, 10, "be_%d.dat", i);
        
        fp1 = fopen(name, "w");
        while(t < tend)
        {
            t = t + h[i];
            x = ((2*h[i])/(2 + h[i]))*((x/h[i])-(6*t*exp(-t/2)));
            fprintf(fp1,"%13.6e %13.6e\n", t,x);
        }
        t = 0;
        x = 2;
        fclose(fp1);

    }
    printf("done");
   return 0;
}