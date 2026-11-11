#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dep[2000005],cnt[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	if(c<=6)
	while(T--)
	{
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			dep[i]=0;
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dep[j]=1e18;
				cnt[j]=1;
			}
			dep[i]=1;
			cnt[i]=1;
			for(int j=i;j<=n;j++)
			{
				for(int k=j+1;k<=n&&a[k]-a[j]<=d;k++)
				{
					if(dep[k]>dep[j]+1)
					{
						dep[k]=dep[j]+1;
						cnt[k]=1;
					}
					else if(dep[k]==dep[j]+1)
					cnt[k]++;
				}
			}
			for(int k=i;k<=n;k++)
			{
				if(cnt[k]==2)
				ans++;
//				if(n<=10)
//				cout<<cnt[k]<<" ";
			}
//			if(n<=10)
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	else if(c>=11&&c<=12)
	while(T--)
	{
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		long long df=a[2]-a[1],st=d/df,lth=st*2;
		if(n==1||df>=d)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<max(0LL,n-lth+1)<<endl;
	}
	else if(c>=13&&c<=14)
	while(T--)
	{
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		long long pos;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
			{
				pos=i;
				break;
			}
		}
		int l=1;
		for(int i=1;i<=n;i++)
		{
			if(i==pos)
			continue;
			while(a[i]-a[l]>d)
			l++;
			if(i-l==2)
			ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}