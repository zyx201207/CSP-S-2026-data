#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long a[200001],ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long l = 1,r = n;
	while (l < r){
		if (a[l] > a[r]){
			a[l] -= a[r];
			if (c[l] != c[r]) ans += a[r];
			r--;
		}
		else if (a[l] < a[r]){
			a[r] -= a[l];
			if (c[l] != c[r]) ans += a[l];
			l++;
		}
		else{
			if (c[l] != c[r]) ans += a[l];
			l++;r--;
		}
	}
	cout << ans;
	return 0;
}
