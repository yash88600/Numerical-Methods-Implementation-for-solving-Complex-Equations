#include<stdio.h>
#include<math.h>

int main()

{
   float t,t_min,t_max,delt;
   float delta;
   float x;
   FILE *fp;

   delta = 1.0e-5;

   t_min = 0.0;
   t_max = 20.0;
   delt = 0.01;

   fp = fopen("plot1d.dat","w");
   t = t_min;

   while ((t-t_max) < delta) {
     x = (2-3*t*t)*(exp(-t/2));
     fprintf (fp,"%13.6e  %13.6e\n",t,x);
     t+= delt;
   }
}
