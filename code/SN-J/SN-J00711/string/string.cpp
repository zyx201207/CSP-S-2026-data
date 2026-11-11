#include <bits/stdc++.h>
using namespace std;
int a;
long long ans = 0;
char c;
string s;
int main()
{
	frepoen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j = 1;j<=(int)a;j++)
		{
			s+=c;
		}
	}
	int l = s.size();
	for(int i = 0;i<l/2;i++)
	{
		if((s[i]-'a') != (s[l-i-1]-'a'))
			ans++;
	}
	cout<<ans;
}
