#include<bits/stdc++.h>
using namespace std;
long long l,n,ans;
char c;
string s;
bool flag;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s="";
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> l;
		if(l>10000)
		{
			l/=10000;
			flag=1;
		}
		cin >> c;
		for(int j=1;j<=l;j++)
		{
			s+=c;
		}
	}
	l=s.size();
	for(int i=(l+1)/2;i<l;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	if(flag) ans*=10000; 
	cout << ans;
	return 0;
}

