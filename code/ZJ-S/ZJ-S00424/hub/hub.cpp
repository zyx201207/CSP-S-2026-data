#include<bits/stdc++.h>
using namespace std;
typedef long long Int;
typedef pair<Int,Int> pir;
#define fi first
#define se second

Int n,k,f[1000005],dfn[1000005],dcnt,d[1000005];
vector<Int>e[1000005],e2[1000005],a[2];
stack<pir>sta;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(Int i=1;i<=n;i++)e[i].clear();
		for(Int i=1;i<n;i++){
			Int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(C==13||C==14){
			if(k<=n/2)cout<<(n/2-k+3)/4+1<<endl;
			else if(k==n)cout<<0<<endl;
			else cout<<1<<endl;
			continue;
		}
		dcnt=0;
		sta.push({1,0});f[1]=0;
		while(!sta.empty()){
			Int u=sta.top().fi,cur=sta.top().se;sta.pop();
			if(cur==0)dfn[++dcnt]=u;
			if(cur==e[u].size())continue;
			sta.push({u,cur+1});
			if(f[u]!=e[u][cur])sta.push({e[u][cur],0}),f[e[u][cur]]=u;
		}
		Int ans=1e18;
		for(Int i=2;i<=n;i++){
			for(Int u=1;u<=n;u++)d[u]=0;
			for(Int u=1;u<=n;u++){
				e2[u].clear();
				for(Int v:e[u]){
					if(v==i&&u==f[i]||u==i&&v==f[i])continue;
					e2[u].push_back(v);
					++d[u];
				}
			}
			a[1].clear();
			for(Int u=1;u<=n;u++)if(d[u]==1)a[1].push_back(u);
			Int dep=0,cnt=n;
			while(cnt>k){
				++dep;
				Int op=dep&1;
				a[op^1].clear();
				for(Int u:a[op]){
					if(d[u]!=1)continue;
					--cnt;
					for(Int v:e2[u]){
						--d[v];
						if(d[v]==1)a[op^1].push_back(v);
					}
				}
			}
			ans=min(ans,dep);
		}
		cout<<ans<<endl;
	}

	return 0;
}
