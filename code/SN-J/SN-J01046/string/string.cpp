#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e5+10;
int a[N];
int ans;
char c[N];
string s;
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	n=s.size();
	s=' '+s;
	ans=n/2;
	for(int i=1;i<=n/2;i++){
		if(s[i]==s[n-i+1])ans--;
	}
	cout<<ans;
	return 0;
}
