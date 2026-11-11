#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=5e5+10;
#define ll long long
int C,T;
int n;
ll lst,d;
ll a[N];
/*
考虑部分分，对于岛屿较少，可以建图+dij最短路计数解决，复杂度n^2logn
对于性质A：
我们总有从第u到第v个岛屿可以选择的数量是固定的，找规律
有假设公差为k，可以令d=[d/k]*k
答案就是n-(2*[d/k]-1)
*/
ll dis[M],cnt[M];
int vis[M];
struct node{
	int v;
	ll w;
	bool operator>(const node &c)const{
		return w>c.w;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
vector<int> e[M];
void dij(int st){
	for(int i=1;i<=n;i++){
		dis[i]=2e18;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[st]=0;
	cnt[st]=1;
	q.push({st,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(dis[u]+1<dis[v]){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
	return;
}
void bf(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) e[i].push_back(j);
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void init(){
	lst=0;
	for(int i=1;i<=n;i++) e[i].clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		bool A=1;
		init();
		ll cha;
		for(int i=1;i<=n;i++){
			ll x;cin>>x;
			if(i==1) lst=x;
			else a[i]=x-lst;
			if(i==2) cha=a[2];
			else if(i!=1 && i!=2) {
				if(a[i]-a[i-1]!=cha) A=0;
			}
		}
		if(A){
			ll tmp=d/cha;
			if(tmp<2) cout<<0<<'\n';
			else cout<<max(0ll,n-(2*tmp-1))<<'\n';
			continue;
		}
		bf();
	}
	return 0;
}
