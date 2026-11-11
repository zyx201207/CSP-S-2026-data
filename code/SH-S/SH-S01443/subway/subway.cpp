#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int w[1001];
int t[500][1000][2];
int p[100000][2];

int a[1000][1000];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
			scanf("%d %d",&t[i][j][0],&t[i][j][1]);
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&p[i][0],&p[i][1]);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
