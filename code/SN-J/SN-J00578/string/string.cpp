#include <bits/stdc++.h>
using namespace std;
const unsigned long long N=2*1e6+10;
unsigned long long n,cnt;
struct AC {
	unsigned long long a;
	char c;
} x[N];
string s[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	unsigned long long l=0;
	for(unsigned long long i=0; i<n; i++) {
		cin>>x[i].a>>x[i].c;
		for(unsigned long long j=0; j<x[i].a; j++) {
			s[l]=x[i].c;
			l++;
		}
	}
	if(l%2!=0) {
		for(unsigned long long i=0; i<(l+1)/2; i++) {
			if(s[i]!=s[l-i-1]) cnt++;
		}
		cout<<cnt;
		return 0;
	} else {
		for(unsigned long long i=0; i<l/2; i++) {
			if(s[i]!=s[l-i]) cnt++;
		}
		cout<<cnt;
		return 0; 
	}
	return 0;
}
