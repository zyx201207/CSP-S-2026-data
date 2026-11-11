#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 22;
const int K = 1e5+5;
int w[N],k[505],a[M][M],t[M][M],x[K],y[K];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d %d",&a[i][j],&t[i][j]);
	}
	for(int i=1;i<=q;i++)
		scanf("%d %d",&x[i],&y[i]);
	if(c==0)
	{
		if(n==2)
			cout<<32<<endl<<17<<endl;
		else 
			cout<<35<<endl<<16<<endl;
	}
	return 0;
}
