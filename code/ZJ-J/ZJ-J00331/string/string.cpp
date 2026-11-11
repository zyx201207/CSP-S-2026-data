#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int n;
ll a[N],sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i = 1;i <= n;++ i){
		cin>>a[i]>>c[i];
		sum += a[i];
	}
	if (sum & 1){
		ll sum2 = 0;
		for (int i = 1;i <= n;++ i){
			sum2 += a[i];
			if (sum2 > sum / 2){
				a[i] --;
				break;
			}
		}
	}
	int l = 1,r = n;
	ll tt = 0,ans = 0;
	while (l <= r){
		if (l == r) break;
		if (c[l] == c[r]){
			if (a[l] > a[r]){
				a[l] -= a[r];
				r --;
			}
			else if (a[l] < a[r]){
				a[r] -= a[l];
				l ++;
			}
			else {
				a[l] = a[r] = 0;
				l ++,r --;
			}
		}
		else {
			if (a[l] > a[r]){
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r --;
			}
			else if (a[l] < a[r]){
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
				l ++;
			}
			else{
				ans += a[l];
				a[l] = a[r] = 0;
				l ++,r --;
			}
		}
	}
	cout<<ans;
	return 0;
}