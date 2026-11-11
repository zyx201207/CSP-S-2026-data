#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m,a[500005],s[500005],l,r,mid,f;
bool ch(int x)
{
	int p=(x+1)/2,s=0;
	for(int i=1;i+x-1<=n;i++)
	{
		for(int j=i;j<i+x;j++)
		{
			s+=abs(a[j]-a[p]);
		}
//		cout<<s<<" ";
		p++;
		if(s<=m)
		{
			return 1;
		}
		s=0;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	cout<<a[1]<<" "<<a[2]<<" "; 
	for(int i=3;i<=n;i++)
	{
//		cout<<a[i]<<" ";
		if(a[i]-a[i-1]!=a[2]-a[1])
		{
			f=1;
			break;
		}
	}
	if(!f)
	{
		int s=m/(a[2]-a[1]),p=0;
		for(int i=1;i<=n;i++)
		{
			s-=i*2;
			if(s<0)
			{
				p=i;
				break;
			}
		}
		if(s+p>=0)
		{
			cout<<(p-1)*2+2;
			return 0;
		}
		if(!p)
		{
			cout<<n;
			return 0;
		}
		else
		{
			cout<<(p-1)*2+1;
			return 0;
		}
	}
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(ch(mid))
		{
			l=mid;
		}
		else r=mid-1;
//		cout<<ch(mid)<<" ";
	}
	cout<<l;
	return 0;
}

