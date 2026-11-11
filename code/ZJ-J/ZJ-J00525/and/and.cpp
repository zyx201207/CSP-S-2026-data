#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],dp[2005][2005];
int pre[200005],suf[200005];
bool A,B,C;
int len(int x){
	int cnt = 0;
	while(x){
		x /= 2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> a[i];
	A = B = C = true;
	int g = log2(n);
	if((1<<g) != n)B = false;
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++){
		g = log2(a[i] + 1);
		if((1<<g) == a[i + 1])A = false;
		if(a[i] != i - 1)B = false;
		if(a[i] >= 4)C = false;
	}
	if(A){
		cout << a[n - k + 1];
	}else if(C){
		int cnt[3];
		for(int i = 1; i <= n; i++){
			cnt[a[i]]++;
		}
		if(cnt[3] >= k){
			cout << 3;
		}else if(cnt[3] + cnt[2] >= k){
			cout << 2;
		}else if(cnt[3] + cnt[1] >= k){
			cout << 1;
		}else if(cnt[3] + cnt[2] + cnt[1] >= k){
			cout << 0;
		}
	}else if(B){
		cout << n - k;
	}else if(k == n - 1){
		int ans = 0;
		pre[0] = suf[n + 1] = (1<<30) - 1;
		pre[n + 1] = suf[0] = (1<<30) - 1;
		for(int i = 1; i <= n; i++)pre[i] = pre[i - 1] & a[i];
		for(int i = n; i >= 1; i--)suf[i] = suf[i + 1] & a[i];
		for(int i = 1; i <= n; i++){
			ans = max(ans,suf[i + 1] & pre[i - 1]);
		}
		cout << ans;
	}else{
		for(int i = 1; i <= k; i++){
			dp[0][i] = 0;
		}
		dp[0][0] = (1<<30) - 1; 
		for(int i = 1; i <= n; i++){
			dp[i][0] = (1<<30) - 1;
			for(int j = 1; j <= k; j++){
				dp[i][j] = max(dp[i - 1][j],(dp[i - 1][j - 1] & a[i]));
			}
		}
		cout << dp[n][k];
	}
	return 0;
}
