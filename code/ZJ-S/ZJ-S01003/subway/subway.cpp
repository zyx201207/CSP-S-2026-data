#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1005;
int c,n,m,d,q,ans;
int psum[N],k[505],w[N];
int a[505][N],t[505][N];
int dis[N][N];
vector<pair<int,int> >path[N],lx[505],l;
vector<int>sum[N];
vector<pair<int,int> >V[N];
struct node{
	int u,v,w;
};
int query(int x,int y){
	int ans=1e9;
	for(auto pth:path[x])
	for(auto i:lx[pth.first]){
		for(auto pt:path[y])
		for(auto j:lx[pt.first]){
			if(pth==pt){
				ans=min(ans,pth.second+pt.second);
			}else
			ans=min(ans,pth.second+pt.second+i.second+j.second+dis[i.first][j.first]);
		//	cout<<ans<<" ";
		}
	}
	return ans;
}
int main(){
/*	ios::sync_with_stdio(false);
	cin.tie(0);*/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m>1000) return 0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			psum[a[i][j]]++;
			path[a[i][j]].push_back({i,t[i][j]});
		}
	}
//	cout<<"*";
	for(int i=1;i<=n;i++){
		l.clear();
		for(int j=1;j<=k[i];j++){
			if(psum[a[i][j]]>1){
				l.push_back({a[i][j],t[i][j]});
				lx[i].push_back({a[i][j],t[i][j]});
			}
		}
		for(auto j:l){
			for(auto k:l){
				if(j==k) continue;
				dis[j.first][k.first]=j.second+k.second;
			}
		}
	}
	for(auto K:lx)
	for(auto k:K)
		for(auto I:lx)
		for(auto i:I){
			if(k==i) continue;
			for(auto J:lx)
			for(auto j:J){
				if(i==k||j==k) continue;
				dis[i.first][j.first]=min(dis[i.first][j.first],dis[i.first][k.first]+dis[k.first][j.first]);
			}
		}
		
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+query(x,y)<<"\n";
	}
	return 0;
}
