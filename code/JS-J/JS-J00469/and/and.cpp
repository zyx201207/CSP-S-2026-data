#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
//I lived to believe the future's in our own hands
//But we're in a plot to a destined end
//Please tell me do the stars above feel the pain
//They do,they do,they're hiding the truth
//Tears blurring my eyes
int a[200005],sum[35],val[200005][35],flag[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read(),ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		flag[i]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30;j++)
		{
			val[i][j]=((a[i]>>j)&1);
			sum[j]+=val[i][j];
		}
	for(int i=30;i>=0;i--)
		if(sum[i]>=m)
		{
			ans+=(1<<i);
			for(int j=i-1;j>=0;j--)
			{
				sum[j]=0;
				for(int k=1;k<=n;k++)
				{
					if(val[k][i]==0)flag[k]=0;
					if(flag[k])
						sum[j]+=val[k][j];
				}
			}
		}
	cout<<ans;
	return 0;
}
