#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,n,d,a[2001],b[2001],ans;
vector<ll>e[2001];
struct node{
	ll x,t;
};
void bfs(ll st,ll en){
	queue<node>q;
	q.push({st,0});
	for(ll i=1;i<=n;i++) b[i]=0;
	b[st]=1;
	ll num=1e18,cnt=0;
	while(q.size()){
		if(cnt>2) return ;
		node x=q.front();
		q.pop();
		for(ll i=0;i<e[x.x].size();i++){
			ll y=e[x.x][i];
			if(b[y]==0){
				b[y]=1;
				q.push({y,x.t+1});
				if(y==en){
					cnt++;
					num=x.t+1;
				}
			}
			else{
				if(y==en&&x.t+1==num) cnt++;
			}
		}
	}
	if(cnt==2) ans++;
}
void solve1(){
	ans=0;
	for(ll i=1;i<=n;i++) e[i].clear(); 
	for(ll i=1;i<n;i++)
		for(ll j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d) e[i].push_back(j);
	for(ll i=1;i<n;i++)
		for(ll j=i+1;j<=n;j++) bfs(i,j);
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		if(n<=300) solve1();
		else cout<<0;
	}
	return 0;
}

