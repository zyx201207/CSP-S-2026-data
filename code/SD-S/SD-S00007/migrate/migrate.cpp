#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2000005;
int c,T,n,lx[N],rx[N];
ll d,x[N];
int dis[N],cnt[N];
int bfs(int u){
	// u -> [u+1,rx[u]]
	for(int i=u;i<=n;i++){
		dis[i]=N; cnt[i]=0;
	}
	queue<int> q;
	q.push(u);dis[u]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v=u+1;v<=rx[u];v++){
			int now=dis[u]+1;
			if(now<dis[v])dis[v]=now,cnt[v]=1;
			else if(now==dis[v]) cnt[v]++;
			if(now==dis[v])q.push(v);
		}
	}
	int ans=0;
	for(int i=u;i<=n;i++){
		if(dis[i]!=N&&cnt[i]==2)ans++;
	}
	return ans;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(11<=c&&c<=12){
		ll diff=n>=2?x[2]-x[1]:1;
		d/=diff;
		if(d<=1)cout<<"0\n";
		else cout<<max(0LL,n-(2*d-1))<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		lx[i]=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(x[mid]+d>=x[i])lx[i]=mid,r=mid-1;
			else l=mid+1;
		}
		l=i,r=n,rx[i]=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(x[i]+d>=x[mid])rx[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=bfs(i);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

/*
freopen 文件名 调试信息 数据范围
*/

