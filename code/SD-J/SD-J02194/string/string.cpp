#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n;
long long a[MAXN];
string s[MAXN];
string c;
string s1,s2;
string s3;
int ans;
int cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			c+=s[i];
		}
	}
	int len=c.length();
	if(len%2==0) {
		for(int i=0; i<len/2; i++) {
			s1+=c[i];
		}
		for(int i=len/2; i<len; i++) {
			s2+=c[i];
		}
	} else {
		for(int i=0; i<len/2; i++) {
			s1+=c[i];
		}
		for(int i=len/2+1; i<len; i++) {
			s2+=c[i];
		}
	}
	for(int i=s2.length()-1; i>=0; i--) {
		s3+=s2[i];
	}

	for(int i=0; i<s2.length(); i++) {
		if(s1[i]!=s3[i])ans++;
	}
	cout<<ans;
	return 0;
}

