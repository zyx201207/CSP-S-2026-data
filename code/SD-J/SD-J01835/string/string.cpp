#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a;
string c;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for(int i = 1;i <= a;i++)
		{
			s+=c;
		}
	}
	for(long long i = 0;i < s.size()/2;i++)
	{
		if(s[i]!=s[n-i])ans++;
	} 
	cout << ans;
	return 0;
}
