 #include<bits/stdc++.h>
#define int long long
using namespace std;
bool px(int a, int b){
	return a > b;
}
signed main(){
//	cout << (0^0) << " " << (1^1) << " " << (0^1);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	int maxa = 0;
	bool pdA = true, pdB = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxa = max(maxa, a[i]);
		int k = 0, cj = 1;
		while(k <= 31 && pdA){
			if(cj-1 == a[i]){
				break;
			}
			k++;
			cj *= 2;
		}
		if(k == 32){
			pdA = false;
		}
		if(a[i] != i-1){
			pdB = false;
		}
	}
	int sum = pow(2, 32)-1;
	if(m == n){//5
		for(int i = 1;i <= n;i++){
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	else if(m == 1){//5
		sum = 0;
		for(int i = 1;i <= n;i++){
			sum = max(sum, a[i]);
		}
		cout << sum;
		return 0;
	}
	else if(maxa < 4){//10
		vector<int> cnt(4, 0);
		for(int i = 1;i <= n;i++){
			cnt[a[i]]++;
		}
		if(cnt[3] <= m){
			cout << 3;
		}
		else if(cnt[3]+cnt[2] <= m){
			cout << 2;
		}
		else{
			cout << 1;
		}
		return 0;
	}
	else if(m == n-1){//10
		vector<int> qz(n+1);
		qz[0] = pow(2, 32)-1;
		vector<int> hz(n+2);
		hz[n+1] = pow(2, 32)-1;
		for(int i = 1;i <= n;i++){
			qz[i] = qz[i-1]&a[i];
		}
		for(int i = n;i >= 1;i--){
			hz[i] = hz[i+1]&a[i];
		}
		int maxn = 0;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn, qz[i-1]&hz[i+1]);
		}
		cout << maxn;
	}
	else if(pdA){//5
		sort(a.begin()+1, a.end(), px);
		cout << a[m];
	}
	else if(pdB){//10
		cout << n-m;
	}
	else{//>=40
		vector<vector<int> > dp(n+1, vector<int> (m+1, 0));
		for(int i = 0;i <= n;i++){
			dp[i][0] = pow(2, 32)-1;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < i;j++){
				for(int k = 1;k <= m;k++){
					dp[i][k] = max(dp[i][k], dp[j][k-1]&a[i]);
				}
			}
		}
		int maxn = 0;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn, dp[i][m]);
		}
		cout << maxn;
	}
}