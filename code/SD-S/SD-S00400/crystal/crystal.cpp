#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(u) (u).begin(),(u).end()
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 500005

using namespace std;
int n,m;
int a[N],b[N];
signed main() {
	freopen("crystal.in","r",stdin);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)  {
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++) {
		b[i] = b[i - 1] + a[i];
	}
	int ans = 0;
//	for(int i = 1;i <= n;i ++) {
//		for(int j = i;j <= n;j ++) {
//			if((j - i + 1) * a[j] - b[j] + b[i - 1] <= m) {
//				ans = max(ans,j - i + 1);
//			}
//		}
//	}
	for(int i = 1,j = 1;j <= n;j ++) {
		if(i < j && (j - i + 1) * a[j] - b[j] + b[i - 1] > m) i ++;
		ans = max(ans,j - i + 1);
	}
	cout<<ans<<"\n";
	return 0;
}

