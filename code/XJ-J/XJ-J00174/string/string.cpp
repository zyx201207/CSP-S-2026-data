#include<bits/stdc++.h>
using namespace std;
int m,n,ans,z;
char a[200005],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n;
		z+=n;
		cin>>s;
		for(int k=0;k<=n-1;k++)
		{
			a[i]=s;
		}
		
	}
	for(int i=0;i<=z-1;i+=0)
	{
		for(int j=z-1;j>=0;j--)
		{
			if(a[i]!=a[j])
			{
				ans+=1;
				
			}
			i++;
		}
	}
	cout<<ans;
	return 0;
}
