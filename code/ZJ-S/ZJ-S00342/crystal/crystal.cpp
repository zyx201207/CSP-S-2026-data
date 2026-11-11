#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n,m,ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum = 0;
	for (int l = 1,r = 1;r <= n;){
		ans = max(ans,r - l + 1);
		r ++;
		if (r > n) break;
		sum += (a[r] - a[r - 1]) * (r - l);
		while (sum > m && l < r){
			sum -= a[r] - a[l];
			l ++;
		}
	}
	cout<<ans;
	return 0;
}