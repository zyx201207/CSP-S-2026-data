#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(&a[0],&a[n]);
	long long temp=0,ans=0,num=0; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			temp+=a[i]-a[j];
		}
		if(temp>=ans&&temp<=m)
		{
			ans=temp;
			num=i+1;
		}
		else if(temp>m)
		{
			break;
		}
		temp=0;
	}
	cout<<num;
	return 0; 
}