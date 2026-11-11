#include<bits/stdc++.h>
using ll=long long;
using namespace std;
using pii=pair<int,ll>;
const int N=2e6+5;

int n;
ll d,x[N];
int nxt[N],c[N][2],tt[N];
struct Node{int u,s1,s2,c;};
bool flag[N];
Node to[N][22];

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],
		tt[i]=c[i][0]=c[i][1]=0,flag[i]=0;
	for(int i=1;i<=n;i++)
	{
		nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		c[i][0]=nxt[i]-max(i,nxt[i-1]);
		if(i>2) c[i][1]=max(nxt[i-1],i)-max(nxt[i-2],i);
		if(nxt[i]==nxt[i-1]) tt[i]=tt[i-1]+1;
		else if(nxt[i-1]==nxt[i]-1) flag[nxt[i]]=1;
//		cerr<<i<<" "<<c[i][0]<<" "<<c[i][1]<<" "<<tt[i]<<'\n';
	}
//	for(int i=1;i<=n;i++) cerr<<i<<" "<<nxt[i]<<'\n';
	for(int i=1;i<=n;i++)
		to[i][0]={nxt[i],c[i][0],flag[i]?0:c[i][1],tt[i]};
	for(int i=1;i<=21;i++)
		for(int j=1;j<=n;j++)
		{
			int v=to[j][i-1].u;
			if(v==to[v][i-1].u) to[j][i]=to[j][i-1];
			else
			{
				int s1=to[j][i-1].s1+to[v][i-1].s1;
				int s2=to[j][i-1].s2+to[v][i-1].s2;
				int c=to[j][i-1].c+to[v][i-1].c;
				to[j][i]={to[v][i-1].u,s1,s2,c};
			}
//			cout<<i<<" "<<j<<" "<<to[j][i].s1<<" "<<to[j][i].s2<<" "<<to[j][i].c<<'\n';
		}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=nxt[i],s=0,cnt=0;
//		cout<<"#"<<i<<" ";
		if(tt[u]>1) continue;
		s+=c[u][1],cnt+=tt[u],u=nxt[u];
//		cout<<cnt<<" ";
		for(int j=21;j>=0;j--)
			if(to[u][j].u!=u&&to[u][j].c+cnt<1)
				s+=to[u][j].s2,u=to[u][j].u;
//		cerr<<u<<" ";
		if(u!=nxt[u]&&!cnt) 
			s+=(!flag[u])&&tt[u]==1?c[u][1]:0,cnt+=tt[u]+flag[u],u=nxt[u];
//		cerr<<cnt<<" "<<s<<" ";
		ans+=s,s=0;
		if(cnt>1) continue;
		for(int j=21;j>=0;j--)
			if(to[u][j].u!=u&&to[u][j].c+cnt<=1)
				s+=to[u][j].s1,u=to[u][j].u;
//		cerr<<s<<'\n';
		ans+=s;
	}
	cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,_;cin>>cid>>_;
	while(_--) solve();
	return 0;
}
