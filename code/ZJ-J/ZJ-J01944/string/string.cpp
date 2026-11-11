#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],n;
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long l=1,r=n,x=0;
	long long t=0;
	while(l<r)
	{
		if(t==0)
		{
			if(c[l]!=c[r])
			{
				if(a[l]>a[r])
				{
					ans+=a[r];
					t=a[l]-a[r];
					r--;x=l;
				}
				else if(a[l]<a[r])
				{
					ans+=a[l];
					t=a[r]-a[l];
					l++;x=r;
				}
				else
				{
					ans+=a[l];
					r--;l++;
					t=0;x=0;
				}
			}
			else
			{
				if(a[l]>a[r])
				{
					t=a[l]-a[r];
					r--;x=l;
				}
				else if(a[l]<a[r])
				{
					t=a[r]-a[l];
					l++;x=r;
				}
				else
				{
					r--;l++;
					t=0;x=0;
				}
			}
		}
		else
		{
			if(x==l)
			{
				if(c[l]!=c[r])
				{
					if(t>a[r])
					{
						ans+=a[r];
						t=t-a[r];
						x=l;r--;
					}
					else if(t<a[r])
					{
						ans+=t;
						t=a[r]-t;
						x=r;l++;
					}
					else
					{
						ans+=t;
						x=0;t=0;
						r--;l++;
					}
				}
				else
				{
					if(t>a[r])
					{
						t=t-a[r];
						x=l;r--;
					}
					else if(t<a[r])
					{
						t=a[r]-t;
						x=r;l++;
					}
					else
					{
						x=0;t=0;
						r--;l++;
					}
				}
			}
			else
			{
				if(c[l]!=c[r])
				{
					if(t>a[l])
					{
						ans+=a[l];
						t=t-a[l];
						x=r;l++;
					}
					else if(t<a[l])
					{
						ans+=t;
						t=a[l]-t;
						x=l;r--;
					}
					else
					{
						ans+=t;
						x=0;t=0;
						r--;l++;
					}
				}
				else
				{
					if(t>a[l])
					{
						t=t-a[l];
						x=r;l++;
					}
					else if(t<a[l])
					{
						t=a[l]-t;
						x=l;r--;
					}
					else
					{
						x=0;t=0;
						r--;l++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
