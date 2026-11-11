#include<bits/stdc++.h>
using namespace std;
long long n,sl[200100],l=1,r,ans=0,shu1,shu2,cnt=0;
char a[200100];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
l=0;r=n+1;
for(int i=1;i<=n;++i)
{
	cin>>sl[i]>>a[i];
}
while(l<r)
{
	if(shu2>shu1)//后大于前 
	{
		if(a[l]!=a[r])
		{
			ans+=shu1;//计算修改数量 
		}
		shu2-=shu1;//抵消  
		shu1=sl[l+1];//更改前
		l++;cnt++;
	}
	else if(shu1>shu2)
	{
		if(a[l]!=a[r])
		{
			ans+=shu2;
		}
		shu1-=shu2;
		shu2=sl[r-1];
		r--;cnt++;
	}
	else if(shu1==shu2)
	{
		if(a[l]!=a[r])
		{
			ans+=shu1;
		}
		shu1=sl[l+1];shu2=sl[r-1];
		l++,r--;
		cnt+=2;
	}
}cout<<ans;
return 0;
}

