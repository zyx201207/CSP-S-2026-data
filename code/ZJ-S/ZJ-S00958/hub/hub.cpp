#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int> g[1000005];
		int d[1000005];
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		if(k<=2){
			cout<<0<<'\n';
			continue;
		}
		int ma=0,ma2=0;
		for(int i=1;i<=n;++i){
			if(d[i]>d[ma]){
				ma2=ma;
				ma=i;
			}
		}
		if(d[ma]+d[ma2]+2>=k) cout<<1<<'\n';
		else cout<<k-(d[ma]+d[ma2]+2)<<'\n';
	}
	return 0;
}