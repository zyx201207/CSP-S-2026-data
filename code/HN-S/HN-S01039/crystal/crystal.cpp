#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,ans=1,f=1;
int a[500010]={0};
int b[500010]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			int x=i*a[i]-b[i];
			if(x<=m)ans=x;
		}
		cout<<ans;return 0;
	}
	int i=1,j=1;
	while(i<=n&&j<=n&&i<=j)
	{
		int x=(j-i+1)*a[j]-(b[j]-b[i-1]);
		if(x>m)i++;
		else
		{
			ans=max(ans,j-i+1);j++;
		}
	}
	cout<<ans;
	
	return 0;
}
//长方形的面积减去目前占的面积，在差小于m的时候长方形越长结果就越大 
//学了数学就是不一样（指思路 
//啥板子都忘了就会爆发出异于常人的思维 
//我就是哲学家（？ 
