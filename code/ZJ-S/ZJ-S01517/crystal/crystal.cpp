#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,m;
ll a[N],q[N];
bool cmp(ll s1,ll s2){
	return s1<s2;
}
bool check(int x){
	ll t,len=0;
	for(int i=x;i<=n;i++){
		t=a[i]*x-q[i]+q[i-x];
		if(t<=m)return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	ll l=1,r=n,ans;
	while(l<=r){
		ll mid=l+(r-l>>1);
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout << ans;
}
