#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
	}
	l=s.size();
	for(int i=0;i<floor(l/2);i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	printf("%lld",ans);
	return 0;
}
