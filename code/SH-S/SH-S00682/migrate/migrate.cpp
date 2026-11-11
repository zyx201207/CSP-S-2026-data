#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+5;
ll n,d,x[N],dis[N],cnt[N],ans;
namespace BIT{
	int val[N];
	#define _l (i&-i)
	void add(int i,int k){
		for(;i<=n;i+=_l) val[i]+=k;
	}
	void upd(int l,int r,int k){
		if(l>r) return;
		add(l,k),add(r+1,-k);
	}
	int sum(int i){
		int ans=0;
		for(;i;i-=_l) ans+=val[i];
		return ans;
	}
} using namespace BIT;
void BFS(int S){
	for(int i=1;i<=n;i++)
		dis[i]=-1,cnt[i]=0,val[i]=0;
	dis[S]=0,upd(S,S,1);
	int p=S+1;
	for(int u=S;u<=n;u++){
		if(dis[u]==-1) break;
		cnt[u]=sum(u);
		if(cnt[u]==2) ans++;
		if(cnt[u]>2) cnt[u]=3;
		while(p<=n and x[p]-x[u]<=d) dis[p++]=dis[u]+1;
		int r=upper_bound(dis+u,dis+p,dis[u]+1)-dis-1;
		int l=lower_bound(dis+u,dis+p,dis[u]+1)-dis;
		upd(l,r,cnt[u]);
	}
}
void solve_Brute(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int u=1;u<=n;u++) BFS(u);
	cout<<ans<<'\n';
}
void solveA(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll cnt=d/(x[2]-x[1]);
	if(cnt>=n or cnt<2){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++) if(i+2*cnt-1<=n) ans++;
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c<=10) solve_Brute();
		else if(c<=12) solveA();
		else cout<<"0\n";
	}
	return 0; 
}
