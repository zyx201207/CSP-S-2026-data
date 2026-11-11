#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string s=" ";
	int len=0;
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		for (int j=1;j<=n;j++)s+=c;
		len+=a;
	}
	int ans=0;
	for (int l=1,r=len;l<=r;l++){
		if (s[l]!=s[r])ans++;
		r--;
	}
	cout << ans;
	return 0;
}
