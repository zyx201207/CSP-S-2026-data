#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n, m, a[100009], sum, mid, x = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mid += a[i];
	}
	mid /= n;
	sort(a + 1, a + n + 1);
	int r = 0, x = 0;
	while(m > 0){
		long long min1 = 0;
		for(int i = 1; i <= n; i++){
			if(mid > a[i]){
				long long ii = abs(a[i]);
				if((mid - ii) < (mid - min1)){
					min1 = a[i];
					r = i;
				}
			} else {
				break;
			}
		}
		m -= (mid - min1);
		sum++;
		x++;
		if(x >= n){
			break;
		}
	}
	cout << sum;
	return 0;
}
