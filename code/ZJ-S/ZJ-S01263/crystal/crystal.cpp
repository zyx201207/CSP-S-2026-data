#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],b[500010];
ll ans=1;
ll ansm[500010];
ll num=0ll;
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll cnt=0;
	ll bi=1;
	ll ai=1;
	for(int i = 1;i < n;i++){
		cnt++;
		while(num+(a[i+1]-a[i])*cnt>m){
			num-=a[i]-a[bi];
			bi++;
			cnt--;
			ans--;
		}
		num+=(a[i+1]-a[i])*cnt;
		ans++;
		ansm[ai++]=ans;
	}
	sort(ansm+1,ansm+ai+1,cmp);
	cout << ansm[1];
	return 0 ;
}
