#include<cstdio>
using namespace std;
int wl(int a,int b);
int ca,c,t,n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	int n[t]={0},d[t]={0},x[t][c]={0},count[t]={0};
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&d);
		for(int j=0;j<t;j++) scanf("%d" ,&x[i][j]);
	}
	ca=x[1]-x[0];
	int s,g;
	for(int k=0;k<t;k++)
	{
		for(int i=0;i<c-1;i++)
		{
			for(int j=i+1;j<c;j++)
			{
				if(wl(i,j)<=s)
				{
					if(wl(i,j)==s) g++;
					else g=0;
				}
			}
			if(g==2) count[k]++;
		}	
	}
	for(int i=0;i<t;i++) printf("%d\n",count[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
int wl(int a,int b)
{
	int len=ca*(b-a);
	if(len%c) return len/c+1;
	else return len/c;
}
