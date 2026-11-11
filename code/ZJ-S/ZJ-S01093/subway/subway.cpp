#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=500005;
int c,n,m,D,q,w[M];
int k,x,y;
int s,t;
vector<pair<int,int> >a[N],b[M];
ll d[N][N];
void read(int &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(j==k) continue;
				d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(D);read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++)
	{
		read(k);
		for(int j=1;j<=k;j++)
		{
			read(x);read(y);
			a[i].push_back(make_pair(x,y));
			b[x].push_back(make_pair(i,y));
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			for(int k=j+1;k<b[i].size();k++)
			{
				x=b[i][j].first,y=b[i][k].first;
				d[x][y]=d[y][x]=min(d[x][y],1ll*b[i][j].second+b[i][k].second);
			}
		}
	}
	floyd();
	for(;q;q--)
	{
		read(s);read(t);
		ll ans=1e18;
		for(int i=0;i<b[s].size();i++)
		{
			for(int j=0;j<b[t].size();j++)
			{
				x=b[s][i].first,y=b[t][j].first;
				ans=min(ans,b[s][i].second+b[t][j].second+d[x][y]);
			}
		}
		cout<<ans+w[s]+w[t];
		putchar('\n');
	}
	return 0;
}