#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		int a; char c;
		cin>>a>>c;
		for (int j=1;j<=a;j++)
			s=s+c;
	}
	int ans=0;
	for (int i=0;i<=(s.size()+1)/2-1;i++){
		if (s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
