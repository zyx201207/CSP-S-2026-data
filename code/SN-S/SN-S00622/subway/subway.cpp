#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,x,y,A,T,ans,w[500010],k[500010],vis[500010];
struct edge{
	ll zhan,val;
};
vector<edge>a[522];
struct node{
	ll xian,vall;
};
vector<node>G[500010];
struct N{
	ll id,vv;
};
queue<N>qq;
void tepanA(ll now,ll to){
	while(!qq.empty()) qq.pop();
	for(int i=0;i<G[now].size();i++){
		node nxt=G[now][i];
		qq.push({nxt.xian,nxt.vall});
	}
	while(!qq.empty()){
		N nxt=qq.front();
		qq.pop();
		for(int i=0;i<a[nxt.id].size();i++){
			edge nxtt=a[nxt.id][i];
			if(nxtt.zhan==to){
				ans=min(nxtt.val+nxt.vv,ans);
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>A>>T;
			G[A].push_back({i,T});
			a[i].push_back({A,T});
		}
	}
	while(q--){
		ans=LLONG_MAX;
		cin>>x>>y;
		if(c>=7&&c<=11){
			tepanA(x,y);
			continue;
		}
		tepanA(x,y);
	}
	return 0;
}
