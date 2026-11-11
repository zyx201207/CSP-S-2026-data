#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, m;
int a[N];
int x[N][30];
int cnt[30]; //统计每个二进制位出现了多少个‘1’ 
int ans[30]; //答案的二进制数  
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		for(int j=0; j<30;  ++j) {
			if(a[i]&(1<<j)) x[i][j]=1;
			cnt[j] += x[i][j];
		}
	}  
	for(int j=29; j>=0; --j) {
//		cout << cnt[j] << ' ';
		if(cnt[j] >= m) {
			ans[j]=1;
			for(int i=1; i<=n; ++i) {
				if(x[i][j]!=1) {
					for(int k=0; k<30; ++k) {
						if(x[i][k]) x[i][k]--, cnt[k]--;
					}
				}
			}
		}
	}
	int ANS=0;
	for(int j=29; j>=0; --j) {
		ANS += (1<<j)*ans[j];
	}
	cout << ANS;
} 
