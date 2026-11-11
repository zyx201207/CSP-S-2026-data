#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[500005];
vector <pair<int,int> > g[500005],t[505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,p=m+1;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int a,ti;
			scanf("%lld%lld",&a,&ti);
			b[p]=a;
			if(g[
			if(j>1){g[p].push_back(make_pair(p-j+1,ti));g[p-j+1].push_back(make_pair(p,ti));}
		    p++;
		}
	}
	for
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		
    }
}
