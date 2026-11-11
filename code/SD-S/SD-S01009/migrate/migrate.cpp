#include<bits/stdc++.h>
#define lltt long long
using namespace std;
const int inf=1e9;
lltt read()
{
	lltt sum=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=(sum<<3)+(sum<<1)+c-'0';
		c=getchar();
	}
	return sum*f;
}
int C,t;
int n;
lltt d,a[2000005];
int dp[2000005];
lltt f[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&t);
//	cout<<"c="<<C<<"\n";
	if(C<=10)
	{
		while(t--)
		{
			scanf("%d",&n);
			d=read();
			for(int i=1;i<=n;i++)
				a[i]=read();
//			for(int i=1;i<=n;i++)
//				cout<<a[i]<<" ";
//			cout<<"\n";
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					dp[j]=inf;
					f[j]=0;
				}
				f[i]=1;
				dp[i]=0;
				for(int j=i+1;j<=n;j++)
				{
					int res=0;
					int l=i,r=j-1;
					while(l<=r)
					{
						int mid=(l+r)>>1;
						if(a[mid]>=a[j]-d)
						{
							res=mid;
							r=mid-1;
						}
						else
							l=mid+1;
					}
					if(!res)
						break;
					lltt cnt=f[res];
					if(res+1<j&&dp[res+1]==dp[res])
						cnt+=f[res+1];
					if(res+2<j&&dp[res+2]==dp[res])
						cnt+=f[res+2];
//					if(cnt>2)
//						break;
					dp[j]=res+1;
					f[j]=cnt;
					ans+=(f[j]==2);
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(C<=12)
	{
//		cout<<"1?\n";
		while(t--)
		{
			scanf("%d",&n);
			
			d=read();
			for(int i=1;i<=n;i++)
				a[i]=read();
			lltt gc=a[2]-a[1];
			if(d<2*gc)
			{
				cout<<"0\n";
				continue;
			}
			if(n==1)
			{
				cout<<"0\n";
				continue;
			}
//			cout<<1<<"\n";
//			cout<<"d="<<d<<" gc="<<gc<<"\n";
			lltt p=d/gc;
			int ans=0;
			
			for(lltt i=1ll;i+2*p-1<=1ll*n;i++)
				ans++;
//				cout<<"n="<<n<<"?\n";
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
