#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
long long ans;
char b[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	for(int i=1;i<=n;++i)for(int j=1;j<=a[i];++j)s+=b[i];
	for(int i=0;i<s.size();++i)if(s[i]!=s[s.size()-i-1])ans++;
	cout<<ans<<'\n';
	return 0;
} 
