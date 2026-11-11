#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum=a[1];
	for(ll i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0; 
} 
