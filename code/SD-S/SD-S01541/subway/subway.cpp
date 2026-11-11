#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005];
vector<pair<int,int> > v[500505];
int f[500505],ans=1e9;

void dfs(int x,int zhong,int sum){
	if(x==zhong){
//		cout<<"x="<<x<<"y="<<zhong<<'\n';
		ans=min(ans,sum);
		return;
	}
	for(auto t:v[x]){
//		cout<<"t1="<<t.first<<" t2="<<t.second<<"\n";
		if(f[t.first]==0){
			f[t.first]=1;
			dfs(t.first,zhong,sum+t.second);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[i+m].push_back({a,t});
			v[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=n+m;i++){
		sort(v[i].begin(),v[i].end());
	}
//	for(int i=1;i<=n+m;i++){
//		cout<<"i="<<i<<'\n';
//		for(auto x:v[i]){
//			cout<<"x1="<<x.first<<" "<<"x2="<<x.second<<'\n';
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e9;
		memset(f,0,sizeof f);
		dfs(x,y,0);
//		cout<<ans<<" "; 
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//kskbl zdjd wkzkbl
