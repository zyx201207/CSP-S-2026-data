#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define cfs cout<<fixed<<setprecision
#define ull unsigned long long
//#define i128 __int128
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
ll a[224524];
ll ans;
int c[40];
bool v[224524];
ll s[224524];
void fdans(int d)
{
	int k=0;
	int w=0;
	for(int i=0;i<=34;i++)
	{
		c[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]>>d)&1)
		{
			s[++k]=a[i];
			for(int j=0;j<=31;j++)
			{
				if((s[k]>>j)&1)
				{
					c[j]++;
				}
			}
		}
	}
	for(int i=d-1;i>=0;i--)
	{
		if(k-w==m)
		{
			break;
		}
		if(c[i]<m)
		{
			continue;
		}
		for(int j=1;j<=k;j++)
		{
			if(v[j])
			{
				continue;
			}
			if(!((s[j]>>i)&1))
			{
				v[j]=1;
				w++;
				for(int p=0;p<=31;p++)
				{
					if((s[j]>>p)&1)
					{
						c[p]--;
					}
				}
			}
		}
	}
	ans=-1;
	int r=0;
	for(int i=1;i<=k;i++)
	{
		if(r>=m)
		{
			break;
		}
		if(v[i]==0)
		{
			if(ans==-1)
			{
				ans=s[i];
				r++;
			}
			else
			{
				ans&=s[i];
				r++;
			}
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	IO;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=0;j<=31;j++)
		{
			if((a[i]>>j)&1)
			{
				c[j]++;
			}
		}
	}
	for(int i=31;i>=0;i--)
	{
		if(c[i]>=m)
		{
			fdans(i);
			break;
		}
	}
	cout << ans;
	return 0;
}

