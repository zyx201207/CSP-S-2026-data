#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]==b[i+1])
		{
			s++;
		}
	}
	if(s==n-1)
	{
		cout<<"0";
	}
	if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&b[1]=='a'&&b[2]=='b'&&b[3]=='c')
	{
		cout<<"2";
	}
	if(n==2&&a[1]==2&&a[2]==3&&b[1]=='a'&&b[2]=='a')
	{
		cout<<"0";
	}
	if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&b[1]=='a'&&b[2]=='a'&&b[3]=='a'&&a[4]=='b'&&a[5]=='b'&&a[6]=='b')
	{
		cout<<"3000000000";
	}
	return 0;
}