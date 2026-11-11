#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans,a[N];
string s;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++)
		s+=c[i];
	}
	for(int i=0;i<s.size()/2;i++)
	if(s[i]!=s[s.size()-i-1])
	ans++;
	cout<<ans;
	return 0;
}
