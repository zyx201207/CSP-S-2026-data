#include<bits/stdc++.h>
using namespace std;
int n,m;
string a2[200005],b2[20005];
long long a10[200005],b10[20005];
void zhuan2_0()
{
	for(int i=0;i<n;i++)
	{
		for(int j=a10[i];j>0;j=j/2)
		{
			a2[i]+=(j%2+'0');
		}
	}
}
void zhuan10_1()
{
	long long int c=1;
	for(int i=0;i<n-m;i++)
	{
		for(int j=0;j<b2[i].size();j++)
		{
			for(int k=0;k<i;k++)
			{
				c*=2;
			}
			b10[i]+=(b2[i][j]-'0')*c;
			c=1;
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a10[i];
	}
	sort(a10,a10+n,cmp);
	zhuan2_0();
	bool f=0;
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<a2[i].size();k++)
		{
			for(int j=i+1;j<m+i;j++)
			{
				if(a2[i][k]!=a2[i+j][k])
					f=1;
			}
			if(f==0)
				b2[i][k]='1';
			else
				b2[i][k]='0';
			f=0;
		}
	}
	zhuan10_1();
	sort(b10,b10+n-m,cmp);
	cout<<b10[0];
	return 0;
}
