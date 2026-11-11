#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
const ll N=1e6+5,mod=1e9+7,inf=1e18;
ll n,m,a[N],ans,h,p[N],g,l;
void dfs(ll cnt,ll sum,ll s){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(cnt==0){
		for(int i=1;i<=n-m+1;i++) dfs(1,a[i],i);
	}
	else{
		for(int i=s+1;i<=n-(m-cnt-1);i++) dfs(cnt+1,sum&a[i],i);
	} 
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int i=30;i>=0;i--) if(a[i]==p[i]-1) h++;
	}
	if(h==n&&n>2000){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

