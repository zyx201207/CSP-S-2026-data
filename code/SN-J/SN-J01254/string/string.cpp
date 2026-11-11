#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100001],num=0,ch=0,bet;
	string c[100001];
	string b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			num++;
			b+=c[i];
		}
	}
	if(num%2==0)
		bet=num/2;
	else
		bet=num/2+1;
	for(int x=0;x<bet;x++)
	{
		if(b[bet-x-1]!=b[bet+x-1])
			ch++;
		else continue;
	}
	if(num%2==0) cout<<ch+1;
	else cout<<ch;
	return 0;
}
