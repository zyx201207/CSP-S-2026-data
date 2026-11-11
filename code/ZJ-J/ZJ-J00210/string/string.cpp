#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],len=0;
char c[200005];
bool p=true;
string b="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>a[1]>>c[1];
	b+=c[1];
	len+=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b+=c[i];
		if(c[i]!=c[i-1])
		{
			p=false;
		}
		len+=a[i];
	}
	if(p)
    {
    	cout<<0;
    	return 0;
	}
	ll cnt=0;
	for(int i=0;i<b.size();i++)
	{
		if(b[i]!=b[b.size()-1-i])
		{
			if(a[i+1]!=a[n-i])
			{
				ll u=max(a[i+1],a[n-i]);
				if(u==a[i+1])
				{
					a[n-i-1]-=u-a[n-i];
					cnt+=(u-a[n-i])*2;
					a[n-i]+=u-a[n-i];	
				}
				else
				{
					a[i+2]-=u-a[i+1];
					cnt+=(u-a[i+1])*2;
					a[i+1]+=u-a[i+1];
				}
			}
			else
			{
				cnt+=a[i+1];
			}
			b[b.size()-1-i]=b[i];
		}
	}
	cout<<cnt;
	return 0;
}
