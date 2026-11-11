#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],c[500005],d[500005],minn[500005],cnt,e;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	memset(minn,0x3f,sizeof(minn));
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			c[i]=a[i+1]-a[i];
		}
		ll sum=m;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k<=j+i-2;k++)
				{
					d[i]+=c[k]*(k-j+1);
				}
				if(d[i]>=0) minn[i]=min(minn[i],d[i]);
				d[i]=0; 
			}
		}
		minn[0]=0;
		minn[1]=0;
		for(int i=1;i<=n;i++)
		{
			cnt=i;
			if(sum-minn[cnt]<0) break;
		}
		cout<<cnt-1;
	}
	else
	{
		e=a[2]-a[1];
		ll sum=m;
		while(sum>=0)
		{
			cnt++;
			sum=m-e*cnt*(cnt+1)/2;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
