#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
int n,m,b[200005][35],maxn,ii;
ll a[200005];
ll mx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int j=1,t=a[i];
		ll mmx=1;
		while(t>0)
		{
			if(t%2==1)
			{
				b[i][j]=1;
			}
			t/=2;
			mx=max(mmx,mx);
			maxn=max(maxn,j);
			mmx*=2;
			j++;
		}
	}
	ll x=1,ss=0,ls=10086;
	for(int i=maxn;i>=1;i--)
	{
		int s=0;
		for(int j=n;j>=x;j--)
		{
			if(b[j][i]==0)
			{
				break;
			}
			s++;
		}
		if(s>=m)
		{
			x=n-s+1;
			ss+=mx;
			mx/=2;
		}
		else if(s<m)
		{
			if(ls==m)
			{
				cout<<ss;
				return 0;
			}
			ii=i;
			break;
		}
		ls=s;
	}
	int f=1,bb=10086;
	for(int i=ii;i>=1;i--)
	{
		ll cnt=0;
		for(int j=n-1;j>=x;j--)
		{
			if(b[j][i]==1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			if(f==1)
			{
				bb=i;
			}		
		}
	}
	if(bb==10086)
	{
		cout<<ss;
	}
	else
	{
		ll cnt=1,f=0,su;
		for(int j=n-1;j>=x;j--)
		{
			if(b[j][bb]==1&&cnt<m)
			{
				if(f==0)
				{
					f=1;
					su=a[j];
				}
				else
				{
					su=su&a[j];
					cnt++;				
				}

			}
		}
		cout<<su;
	}
	return 0;
}