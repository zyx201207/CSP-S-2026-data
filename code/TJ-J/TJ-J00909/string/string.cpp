#include <bits/stdc++.h>
using namespace std;
struct str{
	int shu;
	char fu;
}a[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string b="";
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].shu>>a[i].fu;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=a[i].shu;j++)
		{
			b+=a[i].fu;
		} 	
	}
	int c=b.length();
	if (c%2==0)
	{
		c/=2;
	}
	else
	{
		c=c/2+1;
	}
	int cnt=0;
	for (int i=0;i<c;i++)
	{
		if (b[i]!=b[b.length()-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0; 
}
