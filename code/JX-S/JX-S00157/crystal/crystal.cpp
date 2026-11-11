#include<bits/stdc++.h>
using namespace std;

const int MAXPaiNe=5e5+14;
long long a[MAXPaiNe],ans,num;
long long n,m,ttm;
//chafenf[MAXPaiNe],long long num,ff,l,r;
int main()
{
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int d=a[2]-a[1],spj=1;
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d)
		{
			spj=0;
			break;
		}
	}
	if(spj==0)
	{
		for(int i=1;i<=n;i++)
		{
			ttm=m;
			for(int j=i-1;j>=0;j--)
			{
				if(ttm-(a[i]-a[j])>=0)
				{
					ttm-=(a[i]-a[j]);
					num++;
				}
				else break;
			}
			if(num>=ans) ans=num;
			num=1;
		}
	}
	else
	{
		ttm=m;
		//cout<<d<<'d'<<endl;
		for(int i=d;ans<n;i+=d)
		{
			if(ttm-i>=0)
			{
				ttm-=i;
			//	cout<<ttm<<endl;
				ans++;				
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
