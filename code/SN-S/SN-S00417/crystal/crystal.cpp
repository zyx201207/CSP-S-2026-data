#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> aa(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}
	sort(a.begin(),a.end());
	sort(aa.begin(),aa.end());
	ll ym=0,yy=1,behined=0;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			ym-=(aa[behined]-a[i]);
			yy--;
		}
		for(int j=behined;j<n-1-ans;j++)
		{
			if(aa[j]<aa[j+1])
			{
				ym+=(aa[j+1]-aa[j])*yy;
				
				
				if(ym>m)
				{
					behined=j;
					ym-=(aa[j+1]-aa[j])*yy;
					break;
				}
				yy++;
				for(int z=i;z<yy+i;z++) aa[z]=aa[j+1];
			}
			else yy++;
		}
		if(ans<yy) ans=yy;
	}
	cout<<ans;
	return 0;
}
