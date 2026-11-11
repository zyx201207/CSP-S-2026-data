#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int l,r;
	char c;
}x[200005],y[200005];
signed main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,s=1;
	int a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];		
	}
	for(int i=1;i<=n;i++)
	{
		if(s+a[i]>sum/2)
		{
			x[i].l=s;
			x[i].r=sum/2;
			x[i].c=c[i];
			break;
		}
		x[i].l=s;
		s+=a[i]-1;
		x[i].r=s;
		x[i].c=c[i];
		if(s==sum/2)break;
		s++;
	}
	s=1;
	for(int i=n;i>=1;i--)
	{
		if(s+a[i]-1>sum/2)
		{
			y[n-i+1].l=s;
			y[n-i+1].r=sum/2;
			y[n-i+1].c=c[i];
			break;
		}
		y[n-i+1].l=s;
		s+=a[i]-1;
		y[n-i+1].r=s;
		y[n-i+1].c=c[i];
		if(s==sum/2)break;
		s++;
	}
	int s1=1,s2=1,ans=0;
	for(int i=1;i<=sum/2;)
	{
		if(x[s1].c!=y[s2].c)
		{
			ans+=(min(x[s1].r,y[s2].r)-i+1);
		}
		i=min(x[s1].r,y[s2].r)+1;
		if(x[s1].r>y[s2].r)s2++;
		else if(x[s1].r<y[s2].r)s1++;
		else s1++,s2++;
	}
	cout<<ans;
 	return 0;
}
