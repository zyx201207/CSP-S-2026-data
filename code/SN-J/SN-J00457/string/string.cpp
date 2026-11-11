#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,l=0;
int  s[100010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n>2000) {
		cout<<0;
		return 0;
	}
	char a;
	for(int i=1; i<=n; i++) {
		cin>>m>>a;
		for(int j=1; j<=m; j++) {
			l++;
			s[l]=int(a);
		}
	}
	int ll=l;
	for(int i=1; i<=ll; i++) {
		if(s[i]!=s[l]) {
			s[l]=s[i];
			ans++;
		}
		l--;
	}
	cout<<ans;
	return 0;
}
