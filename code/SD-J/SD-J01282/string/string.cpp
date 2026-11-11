#include<bits/stdc++.h>//24474
using namespace std;
int n;
long long a[5000005], res;
char c[5000005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i]; 
	int l = 1, r = n;
	while(l < r){
		if(c[l] != c[r])
			if(a[l] == a[r]) l ++, r --, res += a[l];
			else if(a[l] > a[r]) a[l] -= a[r], res += a[r], r --;
			else a[r] -= a[l], res += a[l], l ++;
		else
			if(a[l] == a[r]) l ++, r --;
			else if(a[l] > a[r]) a[l] -= a[r], r --;
			else a[r] -= a[l], l ++;
	}
	cout << res;
	return 0;
}

