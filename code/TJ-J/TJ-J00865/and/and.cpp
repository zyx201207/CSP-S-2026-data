#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k[200005]={0};
int ct=0;
int a[200005][36]={0};
int s[36]={0};
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	ans=(1<<31)-1;
	for(int i=0;i<n;i++)
	{
		cin >> k[i];
		long long x=k[i];
		for(int j=0;x>0;j++)
		{
			a[i][j]=x&1;
			if(x&1==1)
			{
				s[j]++;
			}
			x>>=1;
		}
	}
	
	int f=1;
	for(int i=30;i>=0;i--)
	{
		if(s[i]>=m&&f==1)
		{
			f=0;
			for(int j=0;j<n;j++)
			{
				if(a[j][i]==1)
				{
					a[j][32]=2;
				}
			}
			if(s[i]==m)
			{
				for(int j=0;j<n;j++)
				{
					if(a[j][32]==2)
					{
						ans=ans&k[j];
					}
				}
			}
		}
		else if(f==0)
		{
			ct=0;
			for(int j=0;j<n;j++)
			{
				if(a[j][i]==1&&a[j][32]==2)
				{
					ct++;
				}
			}
			if(ct>=m)
			{
				for(int j=0;j<n;j++)
				{
					if(a[j][i]==0)
					{
						a[j][32]=0;
					}
				}
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(a[j][32]==2)
		{
			ans=ans&k[j];
		}
	}
	cout << ans << "\n";
	return 0;
}
