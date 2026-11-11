#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[200005], sum, ans, id[200005], idx;
char c[200005];
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	id[1] = 1;
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		if(id[i] != 1)
			id[i] = id[i-1] + a[i-1];
		sum += a[i];
	}
	ans  = sum/2;
	for(ll i = 1; i  <=  n;  i++)
		if(id[i] >= ans)
			idx = i;
	for(ll i = 1, j = n; i <= idx && j > idx; ){
		if(c[i] == c[j] && n-id[i+1] <= id[j+1]-1){
			ans = ans + (n-id[j+1]-id[i+1]+1);
			if(a[i] - a[j] <= 0){
				i++;
				a[j] = a[j] - a[i];
			}
			else {
				j--;
				a[i] = a[i] - a[j];
			}
		}
		else if(c[i+1]  == c[j])
			i++;
		else if(c[i]  == c[j-1])
			j--;
		else
			i++,  j--;
	}
	sum =  0;
	for(ll i = 1; i <= n; i++){
		if(id[i] != 1)
			id[i] = id[i-1] + a[i-1];
		sum += a[i];
	}
	if(sum <= 10000){
		for(ll i = 1; i <= sum/2; i++){
			ll l =  1, r = n, mid, x, y;
			while(l <= r){
				mid  =  (l+r)/2;
//				cout << mid << ' ';
				if(id[mid] <= i){
					x  =  mid;
					l = mid + 1;
				}
				else
					r = mid -  1;
			}
//			cout << x << endl;
			l =  1, r = n;
			while(l <= r){
				mid  =  (l+r)/2;
//				cout << mid << ' ';
				if(id[mid] <= sum-i+1){
					y  =  mid;
					l = mid + 1;
				}
				else
					r = mid -  1;
			}
			if(c[x] == c[y])
				ans--;
		}
	}
	cout << ans;
	return 0;
}

