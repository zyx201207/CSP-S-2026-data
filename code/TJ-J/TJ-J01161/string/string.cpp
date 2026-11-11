#include <bits/stdc++.h>
using namespace std;
int n;
long long ans,a;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		for(long long i=1;i<=a;i++) s+=c;
	}
	long long l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
