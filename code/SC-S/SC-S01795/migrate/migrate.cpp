#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct k{
	ll d=1e18;
	ll l=0;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll c,t;cin>>c>>t;
	while(t--){
		ll n,d;cin>>n>>d;
		vector<ll> s(n+5);
		for(int i=1;i<=n;i++){cin>>s[i];}
		vector<vector<ll>> g(n+5);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[j]-s[i]<=d){
					g[i].push_back(j);
				}
			}
		}ll ans=0;
		for(int i=1;i<=n;i++){
			queue<ll>t;
			vector<bool> visited(n+5);
			for(int i=1;i<=n;i++){visited[i]=false;}
			t.push(i);
			vector<k> lz(n+5);
			lz[i].d=0;
			lz[i].l=1;
			while(!t.empty()){
				ll l=t.front();
				t.pop();
				if(visited[l])continue;
				visited[l]=true;
				for(auto c:g[l]){
					if(visited[c]==true)continue;
					if(lz[c].d==lz[l].d+1){
						lz[c].l++;
					}else if(lz[c].d>lz[l].d){
						lz[c].l=lz[l].l;
						lz[c].d=lz[l].d+1;
					}
					t.push(c);
				}
			}
			for(int j=i+1;j<=n;j++){
				if(lz[j].l==2){
					ans++;
				}
			}
		}cout<<ans<<"\n";
	}return 0;
}