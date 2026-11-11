#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char b[35];
ll a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	multiset<ll>s;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[m-1];
	return 0;
}
