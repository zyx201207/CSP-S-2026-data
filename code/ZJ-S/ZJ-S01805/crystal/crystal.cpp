#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
ll n,m,a[N];
bool check(ll cnt){
	ll c=0;
	for(int i=1;i<cnt;i++)c+=a[cnt]-a[i];
	for(int i=cnt,j=0;i<=n;i++,j++){
		if(j!=0)c-=a[j+cnt-1]-a[j],c+=(cnt-1)*(a[i]-a[i-1]);
		if(m>=c)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l+1<r){
		ll mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
