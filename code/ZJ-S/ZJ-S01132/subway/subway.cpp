#include <bits/stdc++.h>
#define N 510
#define M 500010
#define int long long
#define IOSIZE 100000
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,IOSIZE,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[IOSIZE+1],*p1=buf,*p2=buf;
inline int rd()
{
	static int x;static unsigned char c;x=0;
	a:c=gc;if(c<'0'||c>'9') goto a;
	b:x=(x<<1)+(x<<3)+(c&0xf),c=gc;if(c>='0'&&c<='9') goto b;
	return x;
}
int dis[N][N];
int t,n,m,d,q,k;
int w[M];
vector<int> nxt[M],len[M];
inline void chkmn(int& x,int y){x=min(x,y);}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	t=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		k=rd();
		while(k--) x=rd(),y=rd(),nxt[x].push_back(i),len[x].push_back(y);
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<nxt[i].size();j++)
			for(int k=0;k<nxt[i].size();k++)
				chkmn(dis[nxt[i][j]][nxt[i][k]],len[i][j]+len[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmn(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		x=rd(),y=rd();
		int ans=LLONG_MAX;
		for(int j=0;j<nxt[x].size();j++)
			for(int k=0;k<nxt[y].size();k++)
				chkmn(ans,len[x][j]+dis[nxt[x][j]][nxt[y][k]]+len[y][k]);
		fprintf(stdout,"%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
