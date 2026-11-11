#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[5005],fa[5005],dis[5005],ans,mp[5005];
struct node{
	ll to;
	ll v;
};
queue<node>q;
void bfs(ll now){
	memset(dis,0x3f,sizeof dis);
	memset(fa,0,sizeof fa);
	q.push({now,0});
	while(q.size()){
		ll nw=q.front().to;
		ll bs=q.front().v;
		q.pop();
		if(bs<dis[nw]){
			dis[nw]=bs;
			fa[nw]=1;
		}else if(bs==dis[nw])fa[nw]++;
		else continue;
		for(ll j=nw+1; j<=n; j++){
			if(a[j]-a[nw]<=d)q.push({j,bs+1});
		}
	}
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1; i<=n; i++)cin>>a[i];
		for(ll i=1; i<n; i++){
			bfs(i);
			for(ll j=i+1; j<=n; j++){
				if(fa[j]==2)ans++;
			}
		}cout<<ans<<'\n';
	}return 0;
}