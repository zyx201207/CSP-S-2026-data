#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200010;
ll n,m;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=a[1];
	for(ll i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}