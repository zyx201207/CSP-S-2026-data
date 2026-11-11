//谢震寰 西安市第三中学 SN-J00739 
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s;
int ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin >>a>>c;
		for(int i=1;i<=a;i++)
		{
			s=s+c;
		}
	}
	int l=s.size();
	for(int i=0;i<ceil(l/2);i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	cout <<ans<<'\n';
	return 0;
}
