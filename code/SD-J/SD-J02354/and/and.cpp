#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans=0;
int m;
int n;
int f1(int x,int y,int k)
{
	if(x==m)
	{
		ans=max(ans,k);
		return 0;
	}
	if(y==1)
	{
		k=k&a[x];
	}
	return f1(x+1,1,k);
	return f1(x+1,0,k);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	 if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}	
		} 
	}
	else{
		f1(0,0,a[1]);	
		f1(0,1,a[1]);
	}
	cout<<ans;
	return 0;
}
