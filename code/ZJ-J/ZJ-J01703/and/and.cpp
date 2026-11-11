#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200007;
ll n,m,a[N],b[N],res,tot=0;
ll p[3001][3001],is[N];
ll wq[20]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000};
int ezs(int x){
	int ret=0,qz=1;
	while(x){
		ret+=(x%10)*qz;
		x/=10;
		qz*=2;
	}
	return ret;
}
bool check(){
	for(int i=1;i<=n;i++){
		int xx=a[i]+1;
		while(xx){
			if(xx!=1&&xx%2==1) return 0;
			xx/=2;
		}
	}
	return 1;
}
void dfs(ll id,ll dep){
	if(dep==m){
		tot=max(tot,res);
		return ;
	}
	if(id>n) return ;
	dfs(id+1,dep);
	ll ress=res;
	if(dep==0) res=a[id];
	else res=res&a[id];
	is[id]=1;
	dfs(id+1,dep+1);
	is[id]=0;
	res=ress;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		ll ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==2){
		ll ans=-2e18;
		for(ll l=1;l<=n;l++)
			for(ll r=l+1;r<=n;r++)
				ans=max(ans,a[l]&a[r]);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==(n-1)){
		ll tmx=0,cur=0,ans=0;
		for(ll i=1;i<=n;i++){
			ll xx=a[i],tt=1;
			for(ll j=1;j<=20;j++) is[j]++;
			while(xx){
				if(xx%2==1) is[tt]--;
				xx/=2;
				tt++;
			}
			tmx=max(tmx,tt-1);
		}
		for(ll i=1;i<=tmx;i++){
			if(is[i]==0) cur=cur*10+1;
			else cur=cur*10;
		}
		for(ll i=1;i<=n;i++){
			ll xx=a[i],tt=1,nw=cur;
			while(xx){
				if(xx%2==0)
					if(is[tt]==1)
						nw+=1*wq[tt];
				xx/=2;
				tt++;
			}
			ans=max(ans,ezs(nw));
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(check()){
		sort(a+1,a+n+1);
		cout<<a[m]<<"\n";
		return 0;
	}
	dfs(1,0);
	cout<<tot<<"\n";
	return 0;
}