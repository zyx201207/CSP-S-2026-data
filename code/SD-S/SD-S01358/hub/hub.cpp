#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll N=1e3+5,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll t,n,k,ff[N],tii,ans,fff[N];
ll h[N],to[N<<1],nxt[N<<1],idx;
ll f[N][N];
void add(ll u,ll v){
	nxt[++idx]=h[u],h[u]=idx,to[idx]=v;
}
ll cnt[N],ss[N];
void dfs(int p){
	if(p==k+1){
		tii++;
		ll si=0;
		for(int i=1;i<=k;i++){
			ss[cnt[i]]=tii;
			if(ff[cnt[i]]!=tii){
				for(int j=h[cnt[i]];j;j=nxt[j]){
					if(ff[to[j]]==tii) si--;
				}
			}
			si++;
			ff[cnt[i]]=tii;
		}
		if(si>2) return;
		ll maxx=0;
		for(int i=1;i<=n;i++){
			if(ss[i]==tii) continue;
			ll minn=INF;
			for(int j=1;j<=n;j++){
				if(ss[j]==tii){
				//	cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
					minn=min(minn,f[i][j]);
				}
			}
			maxx=max(maxx,minn);
		}
		ans=min(maxx,ans);
	//	cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(fff[i]==1) continue;
		fff[i]=1;
		cnt[p]=i;
		dfs(p+1);
		fff[i]=0;
	}
}
int main(){
 	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) h[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=INF;
			}
			f[i][i]=0;
		}
		idx=0;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
			f[u][v]=1;
			f[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		ans=INF;
		dfs(1);
		cout<<ans<<"\n";
	}


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
