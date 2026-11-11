#include<bits/stdc++.h>
using namespace std;
	string s[1000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=1;
	for (int i=1;i<=n;i++) {
		long long a; char b;
		cin>>a>>b;
		for (long long j=1;j<=a;j++) s[cnt++]=b;
	}
	int ans=0;
	for (int i=1;i<=cnt/2;i++) {
		if (s[i]!=s[cnt-i]) ans++;
	}
	cout<<ans;
	
	
	return 0;
}
