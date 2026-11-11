#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d,a[2000010],ans=0;
int C,T,n,lr[2000010][2],mp[2000010];
int g[2000010],f[2000010][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i],mp[i]=f[i][0]=f[i][1]=g[i]=0;
		for(int i=1;i<=n;i++)
		{
			int l=1,r=i;
			while(l<r)
			{
				int mid=l+r>>1;
				if(a[i]-a[mid]<=d)
				r=mid;
				else
				l=mid+1;
			}
			lr[i][0]=l;
			l=i,r=n;
			while(l<r)
			{
				int mid=l+r+1>>1;
				if(a[mid]-a[i]<=d)
				l=mid;
				else
				r=mid-1;
			}
			lr[i][1]=l;
		}
		for(int i=1;i<=n;i++)
		mp[lr[i][0]]++;
		for(int i=1;i<=n;i++)
		{
			if(lr[i][1]!=i)
			g[lr[i][1]]++;
			for(int op=0;op<=1;op++)
			{
				int cnt=i-lr[lr[i][1]][0],chk=lr[i][0]==lr[i-1][0];
				if(i==lr[i][1])
				continue;
				if(cnt>=2)
				continue;
				if(cnt==0)
				f[lr[i][1]][op]+=f[i][op]+g[i]*(op==0);
				else if(op==0)
				{
					if(chk)
					f[lr[i][1]][1]+=f[i][0];
					f[lr[i][1]][1]+=g[i];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int op=0;op<=1;op++)
			{
				if(op==0)
				{
					if(lr[i][0]==lr[i-1][0])
					ans+=1ll*f[i][op]*(mp[i-1]-(lr[i][0]==i-1)-(lr[i-1][0]==i-1));
					ans+=1ll*g[i]*(mp[i-1]-(lr[i][0]==i-1)-(lr[i-1][0]==i-1));
				}
				else
				ans+=1ll*f[i][op]*(mp[i]-(lr[i][0]==i));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}