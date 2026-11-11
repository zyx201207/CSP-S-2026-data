#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10; 
ll c,T;
ll n,d,a[N];
void solve8(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll dif=a[2]-a[1];
	ll stp=d/dif;
	cout<<(stp>=2 ? max(n-(2*stp-1),0ll) : 0)<<"\n";
}
ll L[N],R[N];
void solve8_(){
	cin>>n>>d;
	if(n==1){
		cout<<"0\n";
		return;
	}
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll cur=1;
	for(ll i=1;i<=n;i++){
		while(a[cur]<a[i]-d) cur++;
		L[i]=cur;
	}
	cur=n;
	for(ll i=n;i>=1;i--){
		while(a[cur]>a[i]+d) cur--;
		R[i]=cur; 
	}
//	for(ll i=1;i<=n;i++){
//		cout<<L[i]<<" "<<R[i]<<"\n";
//	}
	ll ans=0,hh=1,tt=0;
	for(ll i=2;i<=n;i++){
		if(R[1]-L[i]+1==2){
			if(hh==1) hh=i;
			tt=i;
		}
	}
	if(hh==1&&tt==0){
		cout<<"0\n";
		return;
	}
	ans=tt-hh+1;
	for(ll i=2;i<=n;i++){
//		cout<<ans<<"\n"; 
		if(R[i]==n) break;
		while(tt<n&&R[i]-L[tt+1]+1>=2) tt++;
		if(R[i]-L[tt]+1!=2) break;
		while(hh<=n&&R[i]-L[hh]+1>2) hh++;
		ans+=tt-hh+1;
	}
	cout<<ans<<"\n";
}
ll dis[N],cnt[N];
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(ll v=n;v>=2;v--){
		dis[v]=0;
		ll cur=v;
		for(ll u=v;u>=1;u--){
			if(u<cur) break;
			while(cur>1&&a[cur-1]>=a[u]-d) dis[--cur]=dis[u]+1;
			if(cur==1) break;
		}
		cnt[v]=1;
		ll hh=v+1,tt=v+1,sum1=0,sum2=1;
		for(ll u=v-1;u>=cur;u--){
			if(dis[u]>dis[u+1]){
				tt=hh-1,hh=u+1;
				sum1=sum2,sum2=0;
			}
			while(tt>=hh&&a[tt]>a[u]+d) sum1-=cnt[tt--];
			cnt[u]=sum1;
			if(cnt[u]==2) ans++;
			sum2+=cnt[u];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		if(c==11||c==12) solve8();
		else if(c==13||c==14) solve8_();
		else solve();
	}
	
	return 0;
}
/*
13 1
5 4
1 3 5 7 9
给了一个数轴，数轴上面有 n 个点
每一次最多跳 d 的距离
如果 u 点到 v 能跳的次数最小的路径有恰好两条不同的 
则称这个点对为双径岛屿对
求双径岛屿对的数量

枚举终点
然后得到前面所有点到这个点的最短路径
然后遍历起点，如果该点能一步到达的点中是其最短路径减一的
到终点的路径数和为 2
那就是我们想要的
*/