#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cnt=0,x=INT_MIN;
	for(int i=2;i<=n;i++){
		ll t=m;
		for(int j=i;j>=1;j--){
			if(t<=0)break;
			else {
				t-=(a[i]-a[j]);
				cnt++;
			}
		}
		x=max(x,cnt);
		cnt=0;
	}
	cout<<x;
	return 0;
}