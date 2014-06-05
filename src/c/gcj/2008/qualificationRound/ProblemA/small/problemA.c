/*
https://code.google.com/codejam/contest/32013/dashboard
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

//
//Declaration of Helper Functions
//

//
//main function
//

int main(void)
{
    int T,resets,iter,S,Q,inner_iter,iterator,i,empty,checker[110];
    char searchEngine[110][1000],Query[1100][1000];
    FILE *fp,*fp1;
    fp = fopen("input","r");
    fp1 = fopen("output.txt","w");
    fscanf(fp,"%d",&T);
    //printf("%dtest\n",T);
    for(iter=0;iter<T;iter++)
    {
        resets = 0;
        fscanf(fp,"%d",&S);
        //printf("S=%d\n",S);
        fscanf(fp,"%d",empty);
        for(inner_iter=0;inner_iter<S;inner_iter++)
        {
            checker[inner_iter] = 0;
            fgets(searchEngine[inner_iter],sizeof searchEngine[inner_iter],fp);
            //printf("Line=%s",searchEngine[inner_iter]);
        }
        fscanf(fp,"%d",&Q);
        //printf("Q=%d\n",Q);
        if(Q!=0)
        fscanf(fp,"%d",empty);
        for(inner_iter=0;inner_iter<Q;inner_iter++)
        {
            fgets(Query[inner_iter],sizeof Query[inner_iter],fp);
            //printf("Line=%s",Query[inner_iter]);
            //set & reset checker
            for(iterator=0;iterator<S;iterator++)
            {
                if(!strcmp(Query[inner_iter],searchEngine[iterator]))
                {
                    //printf("%s",searchEngine[iterator]);
                    if(!checker[iterator])
                        checker[iterator] = 1;
                }
                for(i=0;i<S;i++)
                    if(!checker[i])
                    break;
                if(i==S)
                {
                    resets++;
                    for(i=0;i<S;i++)
                        checker[i] = 0;
                }
            }


        }
        fprintf(fp1,"Case #%d: %d\n",iter+1,resets);
    }
   return 0;
}


