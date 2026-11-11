#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],qian[200005][40],b[60],c2,ans,fang[40],r,l,zhi[60],ting;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fang[1]=1;
	for(int i=2;i<=35;i++)
	{
		fang[i]=fang[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ting=35;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=40;j++)
		{
			b[j]=0;
		}
		c2=0;
		while(a[i]!=0)
		{
			c2++;
			b[c2]=a[i]%2;
			a[i]=a[i]/2;
		}
		for(int j=1;j<=35;j++)
		{
			qian[i][j]=qian[i+1][j]+b[j];
		}
		//cout<<c2<<endl;
		for(;ting>c2;ting--)
		{
			zhi[ting]=i+1;
		}
	}
	r=1;
	for(int i=35;i>=1;i--)
	{
		//cout<<zhi[i]<<" "<<i<<" "<<qian[1][i]<<endl;
		if(qian[r][i]>=m)
		{
			ans=ans+fang[i];
			r=zhi[i];
		}
	}
	cout<<ans<<endl;
	return 0;
} 

