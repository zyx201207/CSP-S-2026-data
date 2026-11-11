#include <bits/stdc++.h>
using namespace std;
long long k[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a[n],c[n],sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
		for(int y = 0;y < n;i++){
			k[i] = c[i];
		}
	}
	for(int i = 0;i < n;i++){
		if(k[i] != k[n]){
			sum++;
		}
		n--;
	}
	cout << sum;
	return 0;
}
