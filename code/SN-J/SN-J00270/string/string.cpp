#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,l=0,num=0;
	cin>>n;
	char a;
	string s;
	for (int i=1;i<=n;i++)
	{
		cin>>m>>a;
		l+=m;
		for (int j=1;j<=m;j++)s+=a;
	}
	int ll=l-1;
	if (l%2==1)ll--;
	for (int i=0;i<l/2;i++)
	{
		if (s[i]!=s[ll-i])num++;
	}
	cout<<num;
	return 0;
} 
