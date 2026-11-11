#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
ll n,a[200005],s[200005],lst,lit,cnt;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=(s[n]+1)/2)
		{
			ll li=i,ls=i;
			lit=s[n]/2-s[i-1];
			lst=s[i]-(s[n]+1)/2;
			while(1)
			{
				if(lst<lit)
				{
					lit-=lst;
					if(c[li]!=c[ls])
					{
						cnt+=lst;
					}
					lst=a[++ls];
				}
				else if(lit<lst)
				{
					lst-=lit;
					if(c[li]!=c[ls])
					{
						cnt+=lit;
					}
					lit=a[--li];
				}
				else
				{
					if(c[li]!=c[ls])
					{
						cnt+=lit;
					}
					lit=a[--li];
					lst=a[++ls];
				}
				if(li==0||ls==n+1)
				{
					break;
				}
			}
			break;
		}	
	}
	cout<<cnt;
	return 0;
}