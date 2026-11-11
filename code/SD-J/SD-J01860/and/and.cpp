#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],cnt;
string s[2005];
string process(int a)
{
	string s;
	int i=1;
	while(a!=0)
	{
		s[i]=char(a%2);
		i++;
		a/=2;
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(s+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=process(a[i]);
	}
	for(int i=n-1;i>=m;i--)
	{
		for(int j=1;j<=2005;j++)
		{
			if(s[i][j]==s[i-1][j])
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
