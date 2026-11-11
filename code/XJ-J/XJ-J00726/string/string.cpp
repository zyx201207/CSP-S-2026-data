#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL n;
string s="";
LL ans=0;
LL len=0;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--) {
		LL x;
		char c;
		cin >> x >> c;
		for(LL i=1; i<=x; i++) {
			s+=c;
		}
	}
	len=s.size();
	bool f=true;
	for(LL i=0; i<len/2; i++) {
		if(s[i]!=s[len-i-1]) {
			f=false;
			ans++;
		}
	}
	if(f==true) {
		cout << 0 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}