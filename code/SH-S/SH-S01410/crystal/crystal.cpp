#include<bits/stdc++.h>
using namespace std;

long long a[500010];
long long d[500010];
int flag = 0;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n;i++){
		d[i] = a[i + 1] - a[i];
	}
	
	if(a[1] == a[n]){
		if(n == m){
			cout << n;
		}
		else{
			cout << n-1;
		}
		return 0;
	}
	

	
	long long x = 0;
	long long minx = 0;
	while(minx <= m && x < n){
		x++;
		minx+=999999;
		for(int i = 1; i <= n - x; i++){
			long long now = 0;
			long long cnt = 1;
			for(int j = i; j < i + x; j++){
				now += d[j] * cnt;
//				cout << d[j] * cnt << " ";
				cnt++;
			}
			
//			cout << "\n";
			minx = min(minx, now);
//			cout << minx << "\n";
			if(minx > m){
				flag = 1;	
			}
		}
	}
	if(flag == 0){
		cout << n - 1;
		return 0;
	}
	
	cout << x;
	
	
	return 0;
} 
