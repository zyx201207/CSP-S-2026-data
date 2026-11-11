#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n,m;
ll a[N];
ll mx = 0;
ll sum = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	ll l = 1;
	for(int r = 1;r <= n;r++){
		sum += a[r];
		while(a[r]*(r-l+1)-sum > m && l <= r){
			sum -= a[l];
			l++;
		}
		mx = max(r-l+1,mx);
	}
	cout << mx;
	return 0;
}
