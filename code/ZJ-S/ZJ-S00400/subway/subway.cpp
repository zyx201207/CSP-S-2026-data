#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

struct rd{
	int v;
	ll w;
	operator < (const rd b) const{
		return w>b.w;
	}
};

int _,n,m,d,q,w[500010],vis[500010],a[500010],t[500010];
ll dis[500010],ans=0;
vector<rd> e[500010];

void dj(int sx){
	priority_queue<rd> q;
	q.push({sx,0});
	dis[sx]=0;
	while(!q.empty()){
		rd k=q.top();q.pop();
		if(vis[k.v]) continue;
		vis[k.v]=1;
		for(auto it:e[k.v]){
			if(dis[it.v]>dis[k.v]+it.w){
				dis[it.v]=dis[k.v]+it.w;
				q.push({it.v,dis[it.v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				e[a[j]].push_back({a[l],t[j]+t[l]});
				e[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dj(x);
		cout<<ans+dis[y]<<endl;
	}
	return 0;
}
