/*
https://code.google.com/codejam/contest/975485/dashboard#s=p1
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
int i,l,x,j,k,lim=1000,m,n,z,y;
char in[10005][20],cl[10005][5],dl[10005][5],res[10005][20];
FILE *fp;
i=0;
fp=fopen("input","r");
while(fscanf(fp,"%s",in[i])!=EOF)
i++;
x=i;
fclose(fp);
j=0;
k=0;
l=atoi(in[0]);
fp=fopen("output.txt","w");
for(i=0;i<l;i++)
{
for(m=0;m<lim;m++)
{
res[k][m]='\0';
cl[k][m]='\0';
dl[k][m]='\0';
}
n=0;
fprintf(fp,"Case #%d:",i+1);
j++;
if(atoi(in[j])==0)
j=j;
else
{
j++;
strncpy(cl[k],in[j],3);
}
j++;
if(atoi(in[j])==0)
j=j;
else
{
j++;
strncpy(dl[k],in[j],2);
}
j++;
lim=atoi(in[j]);
j++;
for(m=0;m<lim;m++,n++)
{
res[k][n]=in[j][m];
if((n!=0&&res[k][n]==cl[k][1]&&res[k][n-1]==cl[k][0]) || (n!=0&&res[k][n]==cl[k][0]&&res[k][n-1]==cl[k][1]))
{
res[k][n]='\0';
res[k][n-1]=cl[k][2];
n--;
}
else
{
if(res[k][n]==dl[k][0])
{
for(y=0;y<n;y++)
if(res[k][y]==dl[k][1])
{
n=-1;
break;
}
}
else if(res[k][n]==dl[k][1])
{
for(y=0;y<n;y++)
if(res[k][y]==dl[k][0])
{
n=-1;
break;
}
}
}
}
if(n<=0)
fprintf(fp," []");
else if(n==1)
fprintf(fp," [%c]",res[k][0]);
else
for(z=0;z<n;z++)
if(z==0)
fprintf(fp," [%c,",res[k][z]);
else if(z==n-1)
fprintf(fp," %c]",res[k][z]);
else
fprintf(fp," %c,",res[k][z]);
fprintf(fp,"\n");
}
return 0;
}
