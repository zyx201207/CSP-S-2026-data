#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+5;
int n,m,ans=0;
int a[MAXN];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n-m+1;i++){
		for(int j=2;j<=m;j++){
			a[i]&=a[j+i-1];
		}
		ans=max(a[i],ans);
	}
	cout << ans;
	return 0;
}
