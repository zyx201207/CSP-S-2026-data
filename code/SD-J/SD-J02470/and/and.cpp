#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[10000000];
	string s[10000000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x;
	char y;
	for(int i=1;i<=n;i++)
	{
		x=a[i]%2;
		y=x+'0';
		s[i]=y+s[i];
	}
	
	return 0;
}
