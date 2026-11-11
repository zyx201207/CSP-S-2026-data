#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,a[500005],ans,f[500005],m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f1=1,f2=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		f1=0;
	}
	int d;
	d=a[2]-a[1];
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]!=d)
		{
			f2=0;
			break;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	f[i]=f[i-1]+a[i];
	if(f1)
	{
		int pos;
		pos=lower_bound(f+1,f+n+1,m)-f;
		if(f[pos]==m)
		cout<<pos+1;
		else
		cout<<min(n,pos);
		return 0;
	}
	if(f2)
	{
		f[0]=0;
		for(int i=1;i<=n;i++)
		f[i]=f[i-1]+i;
		for(int i=1;i<=n;i++)
		f[i]*=d;
		int pos;
		pos=lower_bound(f+1,f+n+1,m)-f;
		if(f[pos]==m)
		cout<<pos+1;
		else
		cout<<min(n,pos);
		return 0;
	}
	for(int i=n;i>=1;i--)//´Ó¸ßÍùµÍÃ¶¾Ù 
	{
//		if(i%500==0)
//		cout<<i<<endl;
		if(a[i]==a[i+1])
		continue;
		if(i<=ans)
		break;
		int ma=0,w=m;
//		cout<<a[i]<<" ";
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=w)
			{
				ma++;
				w-=(a[i]-a[j]);
			}
			else
			break;
		}
		ans=max(ans,ma+1);
	}
	cout<<ans;
	return 0;
}
