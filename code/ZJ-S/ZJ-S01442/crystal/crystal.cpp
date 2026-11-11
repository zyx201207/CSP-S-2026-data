#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N],c[N],hzh[N],dp[N],bu[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(c,0,sizeof c);
	memset(bu,0,sizeof bu);
	memset(hzh,0,sizeof hzh);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i < n;i++){
		c[i] = a[i+1] - a[i];
	}
	for (int i = n-1;i >= 1;i--){
		hzh[i] = hzh[i+1] + c[i];
	}
	int l = 1,r = 1,tot = c[1],cnt = 1,mx = 0;
	while (l <= r && r <= n-1){
		mx = max(mx,cnt);
		if (tot <= m){
			cnt++;
			r++;
			tot += (r - l + 1) * c[r];
		}else{
			cnt--;
			tot -= hzh[l] - hzh[r+1];
			l++;
		}
		mx = max(mx,cnt);
	}
	cout << mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
