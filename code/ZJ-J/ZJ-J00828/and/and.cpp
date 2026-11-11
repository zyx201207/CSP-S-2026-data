#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m;
int a[N];
int num[N];
int b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		num[i] = 1;
	}
	for(int i = 30; i >= 0; i--){
		memset(b, 0, sizeof b);
		int sum = 0;
		for(int j = 1; j <= n; j++){
			if((a[j]>>i)&1){
				b[j] = 1;
			}
			if(b[j]&&num[j]){
				sum++;
			}
		}
		if(sum >= m){
			ans += (1<<i);
			for(int j = 1; j <= n; j++){
				num[j] = (num[j]&b[j]);
			}
		}
	}
	cout << ans;
	return 0;
}
