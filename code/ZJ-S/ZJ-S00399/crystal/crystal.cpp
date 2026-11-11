#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s1[500010];
int s2[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n>30000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<=0)
			{
				s1[i]=s1[i-1]+a[i];
			}
			else
			{
				s2[i]=s2[i-1]+a[i];
			}
		}
		sort(a+1,a+n+1);
		int l=1,r=2,mx=-1e9,t=a[r]-a[l];
		while(r<=n)
		{
			if(t<=m)
			{
				mx=max(mx,r-l+1);
				r++;
				t+=(a[r]-a[r-1])*(r-l);
			}
			else
			{
				int ll=l,rr=r,g;
				while(ll<=rr)
				{
					int mid=(ll+rr)/2;
					g=t-(a[r]*(mid-l+1)-(s2[mid]-s2[l-1])-s1[mid]+s1[l-1]);
					if(rr==ll)
					{
						if(g>m)
						{
							l=r;
							r++;
							t=a[r]-a[l];
							break;
						}
						else
						{
							t=t-(a[r]*(mid-l+1)-(s2[mid]-s2[l-1])-s1[mid]+s1[l-1]);
							l=ll;
							break;
						}
					}
					if(g>=m)
					{
						if(rr-ll==1)
						{
							ll=rr;
						}
						else
						{
							ll=mid+1;
						}
					}
					else
					{
						if(rr-ll==1)
						{
							ll=rr;
						}
						else
						{
							rr=mid-1;
						}
					}
				}
			}
		}
		cout<<mx;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		int l=1,r=2,mx=-1e9,t=a[r]-a[l];
		while(r<=n)
		{
			cout<<l<<" "<<r<<" "<<t<<"\n";
			if(t<=m)
			{
				mx=max(mx,r-l+1);
				r++;
				t+=(a[r]-a[r-1])*(r-l);
			}
			else
			{
				t-=a[r]-a[l];
				l++;
			}
			
		}
		cout<<mx;
	}
	return 0;
}
