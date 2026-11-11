#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+7;
ll a[N],ans[N],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		ll z[N]={};
		ll cnt=1;
		map<ll,ll>zs={};
		for(int i=k;i<=n;i++)
		{
			if(zs[a[i]]==0)
			{
				zs[a[i]]++;
				z[cnt]=a[i];
				cnt++;
			}
			else
			{
				bool ok=1;
				while(cnt!=1&&ok==1)
				{
					if(z[cnt-1]==a[i])ok=0;
					cnt--;
					zs[z[cnt]]--;
					z[cnt]=0;
				}
				zs[a[i]]++;
				z[cnt]=a[i];
				cnt++;
			}
		}
		for(int i=1;i<cnt;i++)
		{
			if(z[i]!=0)ans[z[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
