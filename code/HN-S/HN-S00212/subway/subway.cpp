#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,T,minn=1e15;
long long v,w;
long long mm[500005],vis[500005];
struct node{
	long long first,second;
};
vector<node> k[500005],g[25];
void dfs(long long x,long long ans){
//	cout<<x<<endl;
	if(x==w){
//		cout<<"******"<<endl;
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<g[x].size();i++){
		long long sub=g[x][i].first;
//		cout<<sub<<"----snb"<<endl;
		for(int j=0;j<k[sub].size();j++){
//			cout<<k[sub][j].first<<"----w"<<endl;
			if(!vis[k[sub][j].first]){
				vis[k[sub][j].first]=1;
				dfs(k[sub][j].first,ans+g[x][i].second+k[sub][j].second);
				vis[k[sub][j].first]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>mm[i];
	long long t,l,p;
//	cout<<c<<n<<m<<d<<T<<endl;
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>l>>p;
			g[l].push_back({i,p});
			k[i].push_back({l,p});
		}
	}
	while(T--){
		memset(vis,0,sizeof(vis));
		
		cin>>v>>w;
		vis[v]=1;
		dfs(v,0);
		cout<<minn+mm[v]+mm[w]<<endl;
	}
	return 0;
}  
//
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
