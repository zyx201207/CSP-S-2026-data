#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,t;
int n,a[N],fr[N],bk[N];
long long d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			if(a[2]-a[1]>=d||n<(d/(a[2]-a[1])*2-1))
			{
				cout<<0<<"\n";
			}
			else
			{
				cout<<n-(d/(a[2]-a[1])*2-1)<<"\n";	
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1)fr[i]=i;
				else fr[i]=lower_bound(a+1,a+1+i,a[i]-d)-a;
				if(i==n)bk[i]=i;
				else bk[i]=lower_bound(a+1+i,a+1+n,a[i]+d)-a;
				//if(fr[i]==n+1)fr[i]=1;
				//if(bk[i]==n+1)bk[i]=n;
			}
			int basic=0,ans=0;
			for(int i=2;i<n-1;i++)
			{
				if(i==fr[bk[i]]&&i+1==bk[fr[i+1]]&&fr[i+1]<i)
				{
					basic++;
					//cout<<i<<" "<<i+1<<"\n";
					int lc=1,rc=1,l=fr[i+1],r=bk[i];
					while(1)
					{
						if(l==1)break;
						if(fr[l]==l-1&&bk[l-1]==l)lc++,l--;
						else break;
					}
					while(1)
					{
						if(r==n)break;
						if(bk[r]==r+1&&fr[r+1]==r)rc++,r++;
						else break;
					}
					ans+=lc*rc;
				}
			}
			//cout<<basic<<"\n";
			//for(int i=1;i<=n;i++)cout<<fr[i]<<" "<<bk[i]<<"\n";
			cout<<ans<<"\n";	
		}
	}
	return 0;
}