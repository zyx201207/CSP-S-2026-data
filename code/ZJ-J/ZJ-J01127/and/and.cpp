#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans,f1[200005],f2[200005];
void dfs(ll x,ll cnt,ll sum){
	if(cnt+n-x+1<m)return;
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(x==n+1)return;
	dfs(x+1,cnt,sum);
	if(cnt==0)dfs(x+1,cnt+1,a[x]);
	else dfs(x+1,cnt+1,(sum&a[x]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(ll i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=2000){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++)ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans;
		return 0;
	}if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		f1[1]=a[1];
		f2[n]=a[n];
		for(ll i=2;i<=n;i++)f1[i]=(f1[i-1]&a[i]);
		for(ll i=n-1;i>=1;i--)f2[i]=(f2[i+1]&a[i]);
		ans=max(f1[n-1],f2[2]);
		for(ll i=2;i<n;i++)ans=max(ans,(f1[i-1]&f2[i+1]));
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		cout<<a[m];
	}
	return 0;
}
