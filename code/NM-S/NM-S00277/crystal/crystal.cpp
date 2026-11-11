#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans,f[N],qwe,sl;
long long m,a[N];
bool opa,opb;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			f[qwe]=sl;
			sl=1;
			qwe++;
		}
		else
		{
			sl++;
		}
		if(i==n)
		{
			f[qwe]=sl;
		}
		if(a[i]!=i)opa=true;
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1])opb=true;
	}
	if(n<=5000)
	{
		for(int i=n-f[qwe]+1;i>=1;i-=f[qwe])
		{
			int xans=f[qwe];
			if(qwe>0)qwe--;
			else break;
			int t=i;
			long long nl=m;
			while(t>1)
			{
				t--;
				if(nl>=(a[i]-a[t]))
				{
					nl-=(a[i]-a[t]);
					xans++;
				}
				else break;
			}
			ans=max(ans,xans);
		}
	}
	else
	if(!opa)
	{
		if(m>=1ll*n*(n-1)/2)ans=n;
		else
		{
			int l=1,r=n,res=1;
			while(l<=r)
			{
			    int mid=(l+r)/2;
				if(1ll*(mid*(mid-1))/2>m)
				{
					r=mid-1;
				}
				else
				{
					res=mid;
					l=mid+1;
				}
			}
			ans=res;
		}
	}
	else if(!opb)
	{
		int cha=a[2]-a[1];
		for(int i=n;i>=1;i--)
		a[i]=1ll*a[i]-a[1]+cha;
		if(m>=1ll*n*(n-1)*cha/2)ans=n;
		else
		{
			int l=1,r=n,res=1;
			while(l<=r)
			{
			    int mid=(l+r)/2;
				if(1ll*(mid*(mid-1))*cha/2>m)
				{
					r=mid-1;
				}
				else
				{
					res=mid;
					l=mid+1;
				}
			}
			ans=res;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
