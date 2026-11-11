#include<bits/stdc++.h>
using namespace std;
long long n,a,cn;
char c;
string b[200005],cc[200005],d[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			b[j]=c;
			cn++;
		}
	}
	for(int i=1;i<=cn/2;i++)
	{
		cc[i]=b[i];
	}
	for(int i=a;i>=cn/2+1;i--)
	{
		d[i]=b[i];
	}
	for(int i=1;i<=cn;i++)
	{
		if(cc[i]==d[i])
		{
			cout<<"0";
			return 0;
		}

	}
}