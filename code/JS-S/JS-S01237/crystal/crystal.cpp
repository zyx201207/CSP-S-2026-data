#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PLL pair<ll,ll>
#define fi first
#define se second
const ll N=5e5+10;
const ll P=1e9+7;
ll n,m,a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll d=0;
	ll res=0;
	for(ll i=1,j=1;i<=n;i++){
		while(j<i && d>m){
			d-=a[i]-a[j];
			j++;
		}
		res=max(res,i-j+1);
		d+=(a[i+1]-a[i])*(i-j+1);
	}
	cout<<res;
	return 0;
}