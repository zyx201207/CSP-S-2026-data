#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,e,q;
int w[M],k[N],s[M];
long long d[N][N];
vector<pair<int,int> >line[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&e,&q);
	memset(d,0x3f,sizeof d);
	for(register int i=1;i<=m;++i)
		scanf("%d",&w[i]);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&k[i]);
		for(register int j=1;j<=k[i];++j)
		{
			register int a,t;
			scanf("%d %d",&a,&t);
			line[a].push_back(mp(i,t));
			++s[a];
		}
	}
	for(register int i=1;i<=m;++i)
		for(register int l=0;l<s[i];++l)
			for(register int r=l+1;r<s[i];++r)
				d[line[i][l].first][line[i][r].first]=min((long long)line[i][l].second+line[i][r].second,d[line[i][l].first][line[i][r].first]);
	for(register int i=1;i<=n;++i)
		for(register int j=i+1;j<=n;++j)
			d[i][j]=d[j][i]=min(d[i][j],d[j][i]);
	for(register int i=1;i<=n;++i)
		d[i][i]=0;
	for(register int k=1;k<=n;++k)
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[j][k]);
	while(q--)
	{
		register int x,y;
		long long ans=LONG_LONG_MAX;
		scanf("%d %d",&x,&y);
		for(register int i=0;i<s[x];++i)
			for(register int j=0;j<s[y];++j)
				ans=min(ans,d[line[x][i].first][line[y][j].first]+line[x][i].second+line[y][j].second);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
