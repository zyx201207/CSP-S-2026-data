#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,d[2000010],dep[2000010],vis[2000010],sum[2000010];
vector<int> du[2000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(dep,0,sizeof(dep));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			du[i].clear();
			d[i]=0;
		} 
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			d[u]++,d[v]++;
			du[u].push_back(v);
			du[v].push_back(u);
		}
		if(k==1){
			cout<<0<<"\n";
			continue;
		}
		if(k==2){
			cout<<1<<"\n";
			continue;
		}
		int maxx=0,pos=0;
		for(int i=1;i<=n;i++){
			if(maxx<d[i]){
				maxx=d[i],pos=i;
			}
		}
		if(maxx+1>=k){
			cout<<2<<"\n";
			continue;
		}
	}
	return 0;
}
