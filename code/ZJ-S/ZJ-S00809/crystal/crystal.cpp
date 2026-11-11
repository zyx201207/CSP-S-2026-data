#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1001000], f[1001000], dp[5010][5010];
int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(long long i = 0; i < n; i ++) {
		cin>>a[i];
		f[i] = 0;//all states are 0
		dp[i][i] = 1;//do not link itself
	}
	for(int i = 0; i < n; i ++) {
		//i+1 is the step
		for(int j = 0; j < n; j ++) {
			if(f[j] != -1) {
				long long mn = 9223372036854775806, mnk;
				for(int k = 0; k < n; k ++) {
					if(abs(a[k]-a[j])<=mn && dp[j][k]==0) {
						mn = abs(a[k]-a[j]);
						mnk = k;
					}
				}
				//cout<<mn<<" ";
				f[j] += mn;
				dp[j][mnk] = 1;
			}
			//cout<<f[j]<<" ";
		}//find the best anwsers of the part
		long long mn = 9223372036854775806, mnj;
		for(int j = 0; j < n; j ++) {
			if(f[j] <= mn && f[j] != -1) {
				mn = f[j];
				mnj = j;
			}
		}//find the lowest f[]
		//cout<<f[mnj]<<" ";
		if(f[mnj] > m) {
			cout<<i+1;
			return 0;
		}//judge if need to break
		/*int cnt0 = 0;
		for(int j=0;j<n;j++) {
			if(dp[mnj][j] != 0) {
				cnt0++;
			}
		}
		if(cnt0 == n) {
			cout<<n;
			return 0;
		}*///judge if need to break
		/*for(int j = 0; j < n; j ++) {
			if(f[j] > mn) {
				f[j] = -1;
			}
		}*///delete the anwsers that are not the best
		/*for(int j = 0; j < n; j ++) {
			cout<<f[j]<<" ";
		}*/
		//cout<<endl;
	}
	cout<<n;
	return 0;
}
/*4 7
1 6 4 2*/
