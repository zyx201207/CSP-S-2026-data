#include<bits/stdc++.h>
using namespace std;
long long int n,a,cnt;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[n-i+1])
		{
			cnt++;
		}
	}
	cout<<cnt;
}
