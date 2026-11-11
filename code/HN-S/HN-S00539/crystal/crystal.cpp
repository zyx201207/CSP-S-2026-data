#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500050], maxx, cnt, p[500050];
int main(){
	//Oct31==Dec25?
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 5000&&m <= 1e9){
		sort(a+1, a+1+n);
		for(int i = 2;i <= n;i++){
			int w = m;
			for(int j = i-1;j >= 1;j--){
				if(a[i]-a[j] <= w){
					cnt++;
					w -= (a[i]-a[j]);
				}else{
					break;
				}
			}
			if(cnt == 0){
				continue;
			}
			maxx = max(maxx, cnt+1);
			cnt = 0;
		}
	}else{
		for(int i = 2;i <= n;i++){
			p[i] = abs(a[i]-a[i-1])+p[i-1];
		}for(int i = 2;i <= n;i++){
			p[i] += (i-2)*abs(a[i]-a[i-1]);
			if(p[i] <= m){
				maxx = i;
			}else{
				break;
			}
		}
	}
	cout << maxx;
	return 0;
} 
