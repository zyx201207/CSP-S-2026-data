#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i <= n;i++){
		cin >> a[i];
	}
	int ans = 0;
	int g = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i] > a[i + 1]){
				g = a[i];
				a[i] = a[j];
				a[j] = g;
			}
			g = 0;
		}
	}
	int b = n / 2 ;
	int c = 0;
	int d = 0;
	for(int j = 0;j <= b - 1;j++){
		c += a[b] - a[j];
	}
	if(c == m){
		if(a[b] == a[b + 1]){
			for(int j = b + 1;j = n;j++){
				if(a[b] == a[j]) d++;
			}
			ans += d;
		}
		ans += b;
	}
	else if(c > m){		
		while(c != m){
			b--;
			c -= 1;
		}
		ans += b;
	}
	else{
		while(c != m){
			b++;
			c++;
		}
		ans += b;
	}	
	cout << ans;
	return 0;
} 
