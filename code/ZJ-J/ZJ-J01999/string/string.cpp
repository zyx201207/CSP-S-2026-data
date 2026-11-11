#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	int a;
	char x;
	long long ans=0;
	long long xb=0;
	for (int i=0;i<n;i++)
	{
		cin>>a>>x;
		for (int i=0;i<a;i++)
		{
			s+=x;
		}
		xb+=a;
	}
	long long idx=0;
	for (int i=0;i<=xb/2-1;i++)
	{
		if (s[i]!=s[xb-i-1])
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}