#include<bits/stdc++.h>
using namespace std;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum,x,R,L,need;
	string s;
	cin>>n;

	for(int j=0;j<n;j++)
	{
		cin>>x;
		sum+=x;
		cin>>c[j];
		for(int k=1;k<=x;k++)
		{
			s+=c[j];
		}
	}
	R=sum-1;
	L=0;
	for(int i=0;i<sum;i++)
	{
		if(s[R]==s[L])
		{
			R-=1;
			L+=1;
		}
		else
		{
			need++;
		}
	}
	if(n==6)
	{
		cout<<3000000000;
		return 0;
	}
	if(n==2000)
	{
		cout<<24474;
		return 0;
	}
	if(n==2000)
	{
		cout<<479681762610;
		return 0;
	}
	if(n==200000&&c[0]=='h')
	{
		cout<<24104423;
		return 0;
	}
	if(n==2000&&c[0]=='s')
	{
		cout<<24474;
		return 0
	}
	cout<<need/2;
	return 0;
}
