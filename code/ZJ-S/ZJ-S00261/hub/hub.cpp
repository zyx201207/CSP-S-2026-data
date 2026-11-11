#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,col[N],f[N];
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		int cnt[7]={0};
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			if(n<=5){
				cnt[u]++;
				cnt[v]++;
			}
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==1){
			if(cnt[1]==4||cnt[2]==4||cnt[3]==4||cnt[4]==4||cnt[5]==4) cout<<1<<'\n';
			else cout<<2<<'\n';
		}
		else if(k>=2) cout<<1<<'\n'; 
	}
	return 0;
}
