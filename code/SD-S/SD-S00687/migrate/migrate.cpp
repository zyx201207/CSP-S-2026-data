#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
LL a[N];
int f[N],dp[N];
LL s[N];
LL read()
{
	LL res=0;char c;
	bool f=0;
	do
	{
		c=getchar();
		if(c=='-')f=1;
	}while(c<'0' || c>'9');
	do res=res*10+(c^48),c=getchar();while(c>='0' && c<='9');
	return f?-res:res;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	if(c==11 || c==12)
	{
		while(T--)
		{
			int n=read();LL d=read();
			for(int i=1;i<=n;++i)a[i]=read();
			if(n==1)cout<<0<<"\n";
			else
			{
				LL D=a[2]-a[1];
				if(d<D)cout<<0<<"\n";
				else
				{
					LL t=d/D*2-1;
					if(t!=1 && n-t>0)cout<<n-t<<"\n";
					else cout<<0<<"\n";
				}
			}
		}
	}
	else while(T--)
	{
		int n=read();LL d=read(),ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int from=1;from<n;++from)
		{
			dp[from]=1;s[from]=1;
			for(int l=from,r=from,i=from+1;i<=n;++i)
			{
				while(a[i]-a[l]>d)l++;
				if(l==i)break;
				f[i]=f[l]+1;r=max(l,r);
				while(r+1<i && f[r+1]==f[l])r++;
				dp[i]=s[r]-s[l-1];
				if(dp[i]==2)ans++;
				else if(dp[i]>2)dp[i]=3;
				s[i]=s[i-1]+dp[i];
			}
			for(int i=from;i<=n;++i)
			{
				f[i]=0;dp[i]=0;s[i]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//0 4
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
