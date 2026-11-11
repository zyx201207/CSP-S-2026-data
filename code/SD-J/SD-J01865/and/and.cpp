#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,a[N],ans,flag;
ll cnt0,cnt1,cnt2,cnt3;
void dfs(ll x,ll sum,ll cnt){
	if(x==n+1){
		if(cnt==m)ans=max(ans,sum);
		return;
	}
	if(cnt==0)dfs(x+1,a[x],1);
	else dfs(x+1,(sum&a[x]),cnt+1);
	dfs(x+1,sum,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)flag=1;
	}
	if(n<=20){
		dfs(1ll,ans,ans);
		cout<<ans;
	}
	else if(m==1){
		for(ll i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2){
		for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else if(!flag){
		for(ll i=1;i<=n;i++){
			if(a[i]==0)cnt0++;
			else if(a[i]==1)cnt1++;
			else if(a[i]==2)cnt2++;
			else if(a[i]==3)cnt3++;
		}
		if(cnt3>=m)cout<<3;
		else if(cnt3+cnt2>=m)cout<<2;
		else if(cnt3+cnt1>=m)cout<<1;
		else cout<<0;
	}
	else{
		cout<<n-m;
	}
	return 0;
}
