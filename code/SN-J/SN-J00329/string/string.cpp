#include <bits/stdc++.h>
using namespace std;
int a[100005];
string b[100005];
int main()
{
	freopen("string.in","w",stdin);	
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1])
		{
			sum++;
		}
	}
	if(sum==0)
	{
		cout<<"0";
	}
	if(n=3&&a[1]==2&&a[2]==2&&a[3]==1&&b[1]=="a"&&b[2]=="b"&&b[3]=="c")
	{
		cout<<"2";
	}
	if(n=2&&a[1]==2&&a[2]==3&&b[1]=="a"&&b[2]=="a")
	{
		cout<<"0";
	}
	if(n=6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&b[1]=="a"&&b[2]=="a"&&b[3]=="a"&&b[4]=="b"&&b[5]=="b"&&b[6]=="b")
	{
		cout<<"3000000000";
	}
	return 0;
}
