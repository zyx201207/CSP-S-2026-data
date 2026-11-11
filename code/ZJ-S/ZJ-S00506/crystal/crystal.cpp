#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 5e5+5;
LL n,m,a[MAXN],cur[MAXN],cnt[MAXN],idx=0;
LL ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(LL i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	//¿Î…¢ªØ 
	a[0] = -1e13;
	for(LL i = 1;i <= n;i++){
		if(a[i]!=a[i-1]){
			cur[++idx] = a[i];
		}
		cnt[idx]++;
	}
	for(LL i = 1;i <= idx;i++){
		LL tmpa = cnt[i], tmpm = m;
		for(LL j = i-1;j > 0;j--){
			LL la = cur[i]-cur[j];
			if(tmpm > cnt[j]*la){
				tmpm -= cnt[j]*la;
				tmpa += cnt[j];
			}
			else{
				tmpa += (tmpm/la);
				break;
			}
		}
		ans = max(ans,tmpa);
	}
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
