#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q;
int w[N],a[N],t[23][N],vis[N][22],dis[N][22];
struct node2{
	int to,len,lei;
	bool operator <(const node2 &o)const{
		return len>o.len;
	}
};
struct node{
	int to,lei;

};
vector<node>v[N];

int dij(int s,int e){
	int ans=0x3f3f3f3f,pre=-1;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<node2,vector<node2>>qq;
	for(int i=1;i<=d;i++){
		qq.push((node2){s,t[i][s],i});
		dis[s][i]=t[i][s];
	} 
	while(qq.size()){
		auto f=qq.top();
		qq.pop();
		int u=f.to,lei=f.lei,len=f.len;
		if(vis[u][lei]) continue;
		vis[u][lei]=1;
		for(int i=0;i<(int)v[u].size();i++){
			int ilei=v[u][i].lei,to=v[u][i].to;
			if(ilei==lei){
				if(dis[to][lei]>dis[u][lei]){
					dis[to][ilei]=dis[u][lei];
//					pre=ilei;
					qq.push((node2){to,dis[to][ilei],lei});
				}
			}
			else{
				if(dis[to][ilei]>dis[u][lei]+t[u][lei]+t[u][ilei]){
					dis[to][ilei]=dis[u][lei]+t[lei][u]+t[ilei][u];
//					pre=ilei;
					qq.push((node2){to,dis[to][ilei],ilei});
				}
			}
		}
	}
	for(int i=1;i<=d;i++){
		if(ans>dis[e][i]+t[i][e]) ans=dis[e][i]+t[i][e];
	} 
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[i][a[j]];
			if(j>=2){
				v[a[j-1]].push_back({a[j],i});
			}
		}

	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
} 
