#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,m,num=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    if(num<m)
		{
			for(int j=0;j<=i+1;j++)
		{
			a[j]=a[i+1];
			int d=a[j]-a[i];
			num+=d;
			ans=i-2;
		}
			
	}
    }
	cout<<ans;
	return 0;
}