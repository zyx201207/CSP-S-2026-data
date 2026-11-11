#include<cstdio>
#include<iostream>
using namespace std;
int a[1000005];
int ans,n,m;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }  	
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		for(int j=i;j<=n;j++)
		{
			 for(int k=1;k<=m;k++)
             sum=sum&a[j];
		} 
		ans=max(ans,sum);
    } 
	cout<<ans;
    return 0;
}
