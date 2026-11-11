#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int r=1;
	for (int l=1;l<=n;l++){
		while(r<n && m-(a[r+1]-a[r])*(r-l+1)>=0){
			m-=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
		m+=a[r]-a[l];
	}
	cout << ans;
	return 0;
} 
/*
14:31 开T1
14:34 依旧神秘贪心？不兑好像是双指针 
14:43 通过所有下发样例，好像样例故意给的很小
以便在最后评测时卡掉一些忘记开long long的人 
*/
