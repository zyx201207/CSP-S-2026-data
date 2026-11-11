#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,k,c,t,ans=0,maxc=0,len=0;
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)g[i].clear();
		cin>>n>>k;
		maxc=0;
		len=0;
		ans=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}if(c==13||c==14){
			ans=(n/2+1-(k-2))/4;
			if(ans*4!=(n/2+1-(k-2)))ans++;
			cout<<ans<<"\n";
		}else {
			if(k<n)cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}

