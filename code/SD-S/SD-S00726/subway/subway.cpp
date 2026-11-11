#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,k,a,t,x,y,w[N],dis[N];
vector<pair<int,int>>g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		while(k--){
			cin>>a>>t;
			g[i].push_back({a,t});
			g[a].push_back({i,t});
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<abs(x-y);
	}
	return 0;
}
