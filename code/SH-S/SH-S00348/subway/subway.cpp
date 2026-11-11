#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct sub{
	int v;
	int t;
}; 
vector<sub>lines[N];
int w[N];
ll mp[505][505];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			lines[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int sz=lines[i].size(),j=0;
		for(auto u:lines[i]){
			for(int k=j+1;k<sz;k++){
				auto v=lines[i][k];
				mp[u.v][v.v]=min(mp[u.v][v.v],(ll)u.t+v.t);
			}
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				mp[i][j]=0;
				continue;
			}
			if(mp[i][j]==0) mp[i][j]=mp[j][i];
			else mp[j][i]=mp[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
			} 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=LONG_LONG_MAX;
		for(auto u:lines[x]){
			for(auto v:lines[y]){
				ans=min(ans,mp[u.v][v.v]+u.t+v.t+w[x]+w[y]);
			} 
		}
		cout<<ans<<'\n';
	}
} 
