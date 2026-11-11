#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans,s[N];
bool check(ll x){
	for(int i=1;i<=n-x;i++){
		ll cnt=a[i+x-1]*(x-1)-(s[i+x-2]-s[i-1]);
		if(cnt<=m)return 1;
	}return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=0,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}cout<<ans;
	return 0;
} 
