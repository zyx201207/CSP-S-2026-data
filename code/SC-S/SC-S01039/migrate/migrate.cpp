#include <bits/stdc++.h>
using namespace std;
const long long N=1e8;
int c,t;
long long n,d,a[N],ans,tlen=99999999,r;
void dy(long long q1,long long q2,long long len)
{
	if(q1==q2)
	{
		tlen=min(tlen,len);
		return;
	}
	long long tem=q1+1;
	while(a[tem]-a[q1]<=d&&tem<=q2)
	{
		dy(tem,q2,len+1);
		tem++;
	}	
}
void lj(long long q1,long long q2,long long len)
{
	if(r>2)
	{
		return;
	}
	if(q1==q2&&len==tlen)
	{
		r++;
	    return;
	}
	long long tem=q1+1;
	while(a[tem]-a[q1]<=d&&tem<=q2)
	{
		lj(tem,q2,len+1);
		tem++;
	}	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		tlen=999999;
		r=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				tlen=999999;
				r=0;
				dy(a[j],a[k],0);
				lj(a[j],a[k],0);
				//cout<<tlen<<" "<<r<<endl;
				if(r==2)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		if(i!=t)
		{
			cout<<endl;
		}
	}
	return 0;
}