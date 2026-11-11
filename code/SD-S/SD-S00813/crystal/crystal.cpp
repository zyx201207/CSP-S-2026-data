#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],d1[500005],n,m,cnt,d=1,pos,ans=1,maxt=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-1;i++)
	{
		d1[i]=d1[i-1]+b[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			ans++;
			maxt=max(maxt,ans);
		}
		else
		{
			ans=1;
		}
	}
	bool c=0;
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]<=m)
		{
			pos=i;
			c=1;
			break;
		}
	}
	for(int i=pos;i<=n-1;i++)
	{
		if(cnt+b[i]*(i-pos+1)<=m)
		{
			maxt=max(maxt,++d);
			cnt+=b[i]*(i-pos+1);
		}
		else if(cnt+b[i]*(i-pos+1)>m)
		{
			if(b[i]*(i-pos+1)>m)
			{
				pos=i+1;
				cnt=0;
				d=1;
			}
			else
			{
				cnt+=b[i]*(i-pos+1);
				d++;
				while(cnt>m)
				{
					cnt-=d1[i]-d1[pos-1];
					pos++;
					d--;
				}
				maxt=max(maxt,d);
			}
		}
	}
	cout<<maxt<<endl;
	return 0;
}
