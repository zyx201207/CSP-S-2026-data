#include <bits/stdc++.h>
using namespace std;
string s;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		long long x;
		char y;
		cin>>x>>y;
		for (long long j=1;j<=x;j++) {
			s+=y;
		}
	}
	long long cc=0;
	for (long long i=0;i<=s.size()/2;i++) {
		if (s[i]!=s[s.size()-i]) {
			cc++;
		}
	}
	if (s.size()%2!=0) cc--;
	cout<<cc;
	return 0;
}
