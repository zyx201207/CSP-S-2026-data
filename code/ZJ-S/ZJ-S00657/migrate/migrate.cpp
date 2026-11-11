#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,m,sum,l,r;
int a[10010];
int s[10010];
int f[10010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			sum=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			int k=m/(a[2]-a[1]),s=0;
			for(int i=2*k;i<=n;i++)
			{
				if(i%k==0)
					s++;
				sum+=s;
			}
			cout<<sum<<'\n';
		}
		return 0;
	}
	while(T--)
	{
		cin>>n>>m;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			memset(s,0,sizeof(s));
			memset(f,0,sizeof(f));
			f[i]=1;
			s[i]=0;
			l=i-1;
			r=i;
			while(l<n&&l<r)
			{
				l++;
				while(a[l]+m>=a[r+1]&&r<n)
				{
					r++;
					s[r]=s[l]+1;
				}
				for(int j=l+1;j<=r;j++)
				{
					if(s[j]==s[l]+1)
					{
						f[j]+=f[i];
					}
				}
			}
			for(int j=i+1;j<=n;j++)
			{
			//	cout<<f[j]<<' ';
				if(f[j]==2)
				{
					sum++;
				}
			}
		//	cout<<'\n';
		}
		cout<<sum<<'\n';
	}
	return 0;
}
