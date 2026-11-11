#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define File(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define LL long long
#define fi first
#define se second
const int N = 5e5 + 10;
int n;
LL m;
LL a[N],sum[N];
int main(){
	IOS;
	File("crystal");
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + a[i];
	int L = 1;
	int ans = 0;
	for(int i=1;i<=n;i++){
		while(L < i && a[i] * 1ll * (i - L + 1) - (sum[i] - sum[L-1]) > m) L ++ ;
		ans = max(ans,i - L + 1);
	}
	cout << ans;
	return 0;
}