#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
struct edge{
	int line,num;
};
int c,m,n,d,q,w[maxn],k[maxn],vis[maxn],type=1,h,T=0,type1=1;
vector<edge>g[maxn];
vector<int>gg[maxn];
vector<int>hh;
map<int,int>mp;
map<pair<int,int>,pair<int,int>>st;
map<pair<int,int>,int>stt;
map<pair<int,int>,int>a;
map<pair<int,int>,int>t;
queue<edge>Q;
int bfs(int x,int y){
	memset(vis,0,sizeof(vis));
	while(Q.size())Q.pop();
	Q.push({x,0});
	vis[x]=1;
	while(Q.size()){
		int u=Q.front().line;
		int cntt=Q.front().num;
		Q.pop();
		if(u==y){
			return cntt;
		}
		for(auto v:gg[u]){
			if(vis[v]!=0)continue;
			vis[v]=1;
			Q.push({v,cntt+1});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)type=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[{i,j}]>>t[{i,j}];
			if(T==0){
				T=t[{i,j}];
			}else{
				if(T!=t[{i,j}])type1=0;
			}
			if(j!=1){
				g[a[{i,j}]].push_back({a[{i,j-1}],0});
				g[a[{i,j-1}]].push_back({a[{i,j}],0});
			}
			mp[a[{i,j}]]++;
			st[{a[{i,j}],mp[a[{i,j}]]}]={i,j};
			stt[{a[{i,j}],i}]=j;
			if(mp[a[{i,j}]]>=2){
				h=a[{i,j}];
				hh.push_back(a[{i,j}]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(type){
			int ix=st[{x,1}].first;
			int jx=st[{x,1}].second;
			int jh1=stt[{h,ix}];
			int iy=st[{y,1}].first;
			int jy=st[{y,1}].second;
			int jh2=stt[{h,iy}];
			if(mp[x]<2){
				if(mp[y]<2){
					cout<<w[x]+w[y]+t[{ix,jx}]+t[{ix,jh1}]+t[{iy,jh2}]+t[{iy,jy}];
				}else cout<<w[x]+w[y]+t[{ix,jx}]+t[{ix,stt[{y,ix}]}];
			}else cout<<w[x]+w[y]+t[{iy,jy}]+t[{iy,stt[{x,iy}]}];
		}else if(type1){
			for(auto u:hh){
				int sum=mp[u];
				for(int p=1;p<=sum;p++){
					for(int q=1;q<=sum;q++){
						if(q==p)continue;
						gg[st[{u,p}].first].push_back(st[{u,q}].first);
					}
				}
			}
			int xxx=1e12;
			for(int j=1;j<=mp[x];j++){
				for(int k=1;k<=mp[y];k++){
					xxx=min(xxx,bfs(st[{x,j}].first,st[{y,k}].first));
				}
			}
			cout<<w[x]+w[y]+T*2+T*xxx*2;
		}
		cout<<"\n";
	}
	return 0;
}