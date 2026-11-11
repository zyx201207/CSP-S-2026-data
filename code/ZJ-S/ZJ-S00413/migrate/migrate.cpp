#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=2e6+5;
int c,T;
int n,d,a[N],l[N],r[N];
int dis[N],vis[N],cnt[N];
int q[N],h,t;
int f[N];
void dij(int s){
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0,cnt[i]=0;
	h=1;t=0;
	q[++t]=s;dis[s]=0;cnt[s]=1;vis[s]=1;
	while(h<=t){
		int u=q[h++];
		for(int v=l[u];v<=r[u];v++){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				if(!vis[v]&&cnt[v]<=2) vis[v]=1,q[++t]=v;
			}else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
				if(cnt[v]>1e18) cnt[v]=1e18;
			}
		}
	}
}
void solve1(){
	int ans=0; 
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	int ans=0;
	d/=(a[2]-a[1]);
	if(d==0||d==1){
		cout<<0<<"\n";
		return ;
	}
	cout<<max(0ll,n-2*d+1)<<"\n";
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<0<<"\n";
		return ;
	}
	l[0]=1;
	for(int i=1;i<=n;i++){
		l[i]=l[i-1];
		while(l[i]<i&&a[i]-a[l[i]]>d) l[i]++;	
	}
	r[n+1]=n;
	for(int i=n;i>=1;i--){
		r[i]=r[i+1];
		while(r[i]>i&&a[r[i]]-a[i]>d) r[i]--;
	}
	if(c<=10) solve1();
	else if(c<=12) solve2();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
Maybe [32,48]?
*/
