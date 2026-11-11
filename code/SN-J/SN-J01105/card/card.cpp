#include<bits/stdc++.h>
#define lint long long
using namespace std;
lint n,m,ld,ldx,a[500005],ans[500005],lst[500005],sld[500005],t[500005];
lint cntt[500005],dp[5005][5005],fst[500005];
bool okkk[20002],isf[20002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n * m <= 100000000){
		for(int i = n;i >= 1;i--){
			int x = a[i];
			if(!cntt[x]){
				cntt[x]++;
				fst[x] = i;
				int k = i + 1;
				for(int j = 1;j <= m;j++) dp[i][j] = dp[k][j];
				dp[i][x] = dp[k][x] + 1;
				lst[x] = i;
				continue;
			}
			cntt[x]++;
			int k = fst[x];
			for(int j = 1;j <= m;j++) dp[i][j] = dp[k][j];
			if(cntt[x] <= 2) dp[i][x] = 1;
			lst[x] = i;
		}
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				ans[j] += dp[i][j];
		for(int j = 1;j <= m;j++) cout << ans[j] << " ";
	}else{
		ans[n] = n,sld[n] = n + 1,lst[a[n]] = n;
		for(int i = n - 1;i >= 1;i--){
			int x = a[i];
			ans[i] += i;
			ans[i + 1] -= i;
			if(!lst[x]){
				lst[x] = i;
				sld[i] = sld[i + 1];
				continue;
			}
			int l = lst[x];
			if(l == ld){
				ans[i] -= i;
				ans[l] += i;
				ld = i,ldx = lst[x];
				lst[x] = i;
				continue;
			}
			ans[i] -= i;
			ans[ld] += i;
			ans[l] += i;
			ans[ldx] -= i;
			ld = i,ldx = lst[x];
		}
		for(int i = 1;i <= n;i++) ans[i] += ans[i - 1];
		for(int i = 1;i <= n;i++) t[a[i]] = max(t[a[i]],ans[i]);
		for(int i = 1;i <= m;i++) cout << t[i] << " ";
	}
	return 0;
} 
