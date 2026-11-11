#include <bits/stdc++.h>
using namespace std;
char c[10010000];
long long cnt,a[10010000],ans;
int n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	long long k = 0,l = 1,r = n;
	char lc = ' ';
	while(l < r){
		k += a[l];
		while(l < r && k > 0){
			int p = min(k,a[r]);
			if(c[l] != c[r]){
				ans += p;
			}
			k -= p;
			a[r] -= p;
			if(a[r] == 0)r--;
		}
		lc = a[r];
		l++;
	}
	cout << ans;
	return 0;
}
