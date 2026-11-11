#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005],k[505];
map<pair<int,int>,int>pos;
vector<int>a[505],t[505];
vector<pair<int,int> >by[500005];
int ask(int x,int y){
	if(x==y){
		return 0;
	}
	int ans=1000000000000000001;
	for(auto u:by[x]){
		int i=u.first;
		for(int j=u.second+1;j<=k[i];j++){
			ans=min(ans,t[i][pos[{i,x}]]+t[i][pos[{i,a[i][j]}]]+ask(a[i][j],y));
		}
	}
	
	return ans;
}
signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			by[aa].push_back({i,j});
			pos[{i,aa}]=j;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(x==y?0:w[x]+w[y])+ask(x,y)<<"\n";
	}
	return 0;
}
