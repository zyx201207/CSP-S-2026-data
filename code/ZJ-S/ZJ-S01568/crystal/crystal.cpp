#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5;
int n;
long long a[N];
long long m;
long long b[N];
long long f[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int cur_ans;
		for(int j = i; j >= 1; j--){
			long long needm = (i - j) * a[i] - f[i - 1] + f[j - 1];
			if(needm <= m){
				
				cur_ans = i - j + 1;
				if(cur_ans > ans){
					ans = cur_ans;
				}
			}
			else break;
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
