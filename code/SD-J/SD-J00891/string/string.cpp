#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
LL n;
LL l;
char c;
LL ans=0;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>l>>c;
		for (int j=1;j<=l;j++) {
			s+=c;
		}
	}
	int len=s.size();
	s=" "+s;
	for (int i=1;i<=len/2;i++) {
		if (s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
 

