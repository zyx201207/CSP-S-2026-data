#include <bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
const int N=2e6+10;
const LL inf=9e18;
int c,T,n;
LL d,x[N],cnt[N],dw[N];
struct Edge{
	int v,w;
};
vector<Edge>g[N];
inline bool dist(LL u,LL v){
	int cnt=0;
	while(u<v){
		int p=upper_bound(x+1,x+2+n,u+d)-x-1;
		if(u==x[p]) return false;
		u=x[p],cnt++;
		if(cnt>1) return false;
	}
	return true;
}
struct Node{
	int c,w;
	bool operator<(const Node &t)const{
		return t.w<w;
	}
};
priority_queue<Node>q;
inline int count(int u,int v){
	for(R int i=1;i<=n;i++) dw[i]=inf,cnt[i]=0;
	q.push({u,0});
	dw[u]=0,cnt[u]=1;
	while(q.size()){
		Node t=q.top();
		q.pop();
		if(cnt[t.c]>2) continue;
		for(R int i=0;i<g[t.c].size();i++){
			int v=g[t.c][i].v,w=g[t.c][i].w;
			if(dw[v]>dw[t.c]+w){
				dw[v]=dw[t.c]+w;
				cnt[v]=cnt[t.c];
				q.push({v,dw[v]});
			}else if(dw[v]==dw[t.c]+w) cnt[v]+=cnt[t.c];
		}
	}
	return cnt[v];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(R int i=1;i<=n;i++) g[i].clear();
		for(R int i=1;i<=n;i++) cin>>x[i];
		x[n+1]=inf;
		for(R int i=1;i<=n;i++)
			for(R int j=i+1;j<=n;j++)
				if(dist(x[i],x[j]))
					g[i].push_back({j,1});
		LL ans=0;
		for(R int i=1;i<=n;i++)
			for(R int j=i+2;j<=n;j++)
				if(count(i,j)==2)
					ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
