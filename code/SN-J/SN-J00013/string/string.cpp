#include<bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	long long sum = 0, s;
	cin >> n;
	
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		s += a[i];
		cin >> c[i];
	}
	
	int g = n;
	for(int i = 1; i <= n / 2 + 1; i ++){
		if(c[i] != c[g - i + 1]){
			sum += min(a[i], a[g - i + 1]);
		}
			
		a[i] -= min(a[i], a[n - i + 1]);
		a[n - i + 1] -= min(a[i], a[g - i + 1]);
			
		if(a[n - i + 1] == 0){
			g --;
		}else if(a[i] == 0){
			g ++;
		}
	}
	
	cout << sum;
	
	return 0;
}
