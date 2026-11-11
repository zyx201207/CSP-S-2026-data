#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[600000],s[600000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	int ans = 0;  
	for(int r=1,l=0;r<=n;r++){
		while(a[r] * (r-l+1) - (s[r] - s[l-1]) > m) l++;
		ans = max(ans, r-l+1);
	} 
	cout << ans << endl;
} 
