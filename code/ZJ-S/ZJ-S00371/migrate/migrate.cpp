#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,MN=5005,inf=0x3fffffff;
ll c,t,n,d,a[N],cnt[N],dis[N];
void dfs(ll x,ll sum){
	ll pos=upper_bound(a+1+x,a+n+1,a[x]+d)-a-1;
	for(int i=pos;i>x;i--){
		if(sum+1>dis[i])continue;
		else if(sum+1==dis[i])cnt[i]++;
		else dis[i]=sum+1,cnt[i]=1;
		dfs(i,sum+1);
	}
}
void work1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		fill(cnt+i+1,cnt+1+n,0);
		fill(dis+i+1,dis+1+n,inf);
		dfs(i,0);
		for(int j=i+1;j<=n;j++)ans+=(cnt[j]==2);
	}
	cout<<ans<<'\n';
	return;
}
void work3(){
	ll c=a[2]-a[1];
	ll s=d/c;
	if(s<=1)cout<<0<<'\n';
	else cout<<max(0ll,n-s-s+1)<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=10)work1();
		else if(c<=12)work3();
		else work1();
	}
}
