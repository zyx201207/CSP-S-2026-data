#include<bits/stdc++.h>
//priority operator unique unsigned; 
using namespace std;
//const int N=;
long long n,m,mn=1e18,mx=-1e18,ans,cnt,cnt2,a[500005],c[500005];
bool cmt(long long x,long long y)
{
	if(x<0&&y<0)
	{
		return x>y;
	}
	return x<y;
}
bool choose(int x)
{
	cnt2=0;
	int ok=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-ans;
	} 
	sort(c+1,c+n+1);
	long long p=m;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=0&&abs(c[i])<=p)
		{
			ok=1;
			p-=abs(c[i]);
			cnt2++;
		}
	}
	return ok;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
		mx=max(a[i],mx);
		mn=min(a[i],mn);
	}
	ans/=n;
	long long l=mn-1,r=mx+1;
	while(l+1<r)
	{
		
		if(choose(ans)&&cnt2>=cnt)
		{
			cnt=max(cnt,cnt2);
			l=ans;
		}
		else
		{
			r=ans;
		}
		ans=(l+r)/2;	
	}
	if(choose(ans))
	{
		cnt=max(cnt,cnt2);
	}
	cout<<cnt<<endl;
	return 0;
}

