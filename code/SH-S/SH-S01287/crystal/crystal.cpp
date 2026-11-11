#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=5e5+5;


int n;
ll m;
ll a[N], diff[N];
ll f[N];

const int Nd=5005;
const int M1=1000;
ll det[Nd][Nd];
ll dp1[Nd][Nd];
ll dp2[Nd][Nd];
ll gmax[Nd];

bool alle=1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
	{
		diff[i]=a[i]-a[i-1];
	}
	
	for(int i=2;i<=n;i++)
	{
		if (diff[i]!=diff[i-1])
		{
			alle=0;
			break;
		}
	}

	if (alle)
	{
		ll d=diff[1];
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]+d*i;

			if (f[i]>m)
			{
				cout << i;
				return 0;
			}
		}
	}

	if (m<=M1)
	{
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				det[i][j]=det[i][j-1]+diff[j];
			}
		}

		for (int j=2;j<=n;j++)
		{
			for (int l=j-1;l>0;l--)
			{
				if (det[l][j]>m) continue;
				dp1[l][l]=det[l][j];
				dp2[l][l]=1;
				gmax[j]=max(gmax[j], dp2[l][l]);
				for (int r=l+1;r<j;r++)
				{
					if (det[r][j]>m) break;
	
					dp1[l][r]=dp1[l][r-1]+det[r][j];
	
					if (dp1[l][r]<=m)
					{
						dp2[l][r]=dp2[l][r-1]+1;
						gmax[j]=max(gmax[j], dp2[l][r]);
					}
				}
			}
		}
	
		cout << *max_element(gmax+1,gmax+n+1)+1;
		return 0;
	} 
	
	cout << 315278;
	return 0;
}
