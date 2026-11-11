#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen(stdin,"r",and.in);
	freopen(stdout,"w",and.out);
	ll a[100007];
	ll n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	ll maxn=a[0];
	for(int i=1;i<m;i++){
		maxn=maxn&a[i];
	}
	cout << maxn;
	return 0;
}

