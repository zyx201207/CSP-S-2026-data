#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010];
char c[200010];
string s,t;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i] >> c[i];
		for (int j=1;j<=a[i];j++) {
			s+=c[i];
		}
	}
	t=s;
	reverse(t.begin(),t.end());
	int ans=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]!=t[i]) ans++;
	}
	cout <<ans/2; 
	return 0;
}//rp++
