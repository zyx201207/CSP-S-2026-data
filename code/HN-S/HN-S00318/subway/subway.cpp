#include<cstdio>
using namespace std;
int qj(int a,int b);
int w[100]={0},k[100]={0},r[100][100]={0},t[100]={0},s[100],e[100],q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)
		{
			scanf("%d",&r[i][j]);
			scanf("%d",&t[r[i][j]]);
		}
	}
	for(int i=0;i<q;i++) scanf("%d %d",&s[i],&e[i]);
	for(int i=0;i<q;i++)
	{
		printf("%d\n",qj(s[i],e[i]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int qj(int a,int b)
{
	int time=0,now=a,v[q],count=0,i;
	
	while(now!=b)
	{
	
		time+=w[now];
		time+=2*t[now];
		now++; 
	}
	time+=w[b];
	return time;
}
