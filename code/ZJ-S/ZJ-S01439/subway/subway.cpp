#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+7,M=5e5+7;
int c,n,m,d,q;
int w[M];
long long now[M]={};
bool vis[M]={};
vector<pair<int,int> > vec[N],edge[M];
map<long long,long long> mp;
void dfs(long long x){
	long long xf=x;
	for(int i=1;i<=m;i++) now[i]=1e18+7,vis[i]=0;
	now[x]=0,vis[x]=1;
	for(int i=1;i<=m-1;i++){
		long long minn=1e18+7,mink;
		for(pair<int,int> y:edge[x]){
			if(!vis[y.first]){
				now[y.first]=min(now[y.first],now[x]+y.second);
				if(now[y.first]<minn){
					minn=now[y.first];
					mink=y.first;
				}
			}
		}
		vis[mink]=1;
		x=mink;
		mp[xf*10000000+x]=minn;
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			for(pair<int,int> x:vec[i]){
				int fir=x.first,sec=x.second;
				edge[fir].push_back({a,sec+t});
				edge[a].push_back({fir,sec+t});
			}
			vec[i].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<mp[1ll*x*10000000+y]+w[x]+w[y]<<endl;
	}
	return 0;
}
