#include <bits/stdc++.h>
using namespace std;
#define int long long
#define CK cerr<<"\n"<<1.0*fabs(&ED-&ST)/1024/1024<<"MB\n";
bool ST;
const int N=1000010;
int C,T,n,m;
int uu,vv;
vector<int>edge[N];
int dl[N],he,ta,tt[N],du[N];
int siz[N],son[N],dep[N],tot[N],fa[N];

int dp[N];
void dfs(int now,int p){
	siz[now]=1,dep[now]=dep[p]+1,fa[now]=p;
	for(int to:edge[now]){
		if(to==p) continue;
		dfs(to,now);
		tt[to]=now;
		++du[now];
		siz[now]+=siz[to];
		if(siz[to]>siz[son[now]]) son[now]=to;
	}
}
bool ED;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	for(int MF=1;MF<=T;++MF){
		cin>>n>>m;
		for(int i=1;i<n;++i){
			cin>>uu>>vv;
			edge[uu].push_back(vv),edge[vv].push_back(uu);
		}
		if(m>=n){
			cout<<0<<"\n";
			
			he=1,ta=0;
			for(int i=1;i<=n;++i){
				edge[i].clear(),du[i]=tt[i]=0;
			}
			continue;
		}
		if(n<=5){
			cout<<1<<'\n';
			continue;
		}
		dfs(1,0);
		he=1,ta=0;
		for(int i=1;i<=n;++i){
			if(du[i]==0){
				dl[++ta]=i;
			}
		}
		int rr=n;
		if(edge[1].size()==1) --rr;
		for(int i=1;i<=n;++i){
			int k=ta;
			while(he<=k){
				int now=dl[he];
				++he;
				--du[tt[now]];
				--rr;
				if(du[tt[now]]==0) dl[++ta]=tt[now];
			}
			if(i==1) --rr;
			else rr-=2;
			
			if(rr<=m){
				cout<<i<<'\n';
				break;
			}
		}
		
		he=1,ta=0;
		for(int i=1;i<=n;++i){
			edge[i].clear(),du[i]=tt[i]=0;
		}
	}
	CK
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/