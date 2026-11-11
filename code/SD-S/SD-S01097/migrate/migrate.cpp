#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll _,T,n,d,mn=1e18,sum=0;
ll a[N];bool f[N],p[N];
bool check(ll l,ll r){
	ll mx=0;
	for(ll i=l;i<r;i++) mx=max(mx,a[i+1]-a[i]);
	return (mx>d);
}
void dfs(ll l,ll r,ll x){
	if(sum>2) return ;
	if(x==r){
//		cout<<l<<" "<<r<<":\n";
//		for(int i=l;i<=r;i++) cout<<p[i]<<" ";
		ll lt=a[l-1],cnt=0;bool flag=0;
		for(ll i=l;i<=r;i++){
			if(p[i]&&a[i]-lt>d){flag=1;break;}
			if(p[i]) lt=a[i],cnt++;
		}
		if(a[r+1]-lt>d) flag=1;
		else cnt++;
		if(!flag){
			if(cnt<mn) mn=cnt,sum=1;
			else if(cnt==mn) sum++;
		}
//		cout<<"\n"<<sum<<"\n";
		return ;
	}
	p[x+1]=1,dfs(l,r,x+1),p[x+1]=0,dfs(l,r,x+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i],f[i]=0;
//		cout<<n/2<<"\n";
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(f[i]) continue;
			for(ll j=i+2;j<=n;j++){
				if(f[j]||check(i,j)) continue;
				for(ll k=1;k<=n;k++) p[k]=0;
				mn=1e18,sum=0,dfs(i+1,j-1,i);
				if(sum==2){f[i]=f[j]=1,ans++;break;}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
