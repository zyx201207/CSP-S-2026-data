//草木逢春，慧如恒沙。神爱世人，妲门永存！！！ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//bool cmp
const int maxn=2e5+10.27;
ll n,m;
ll a[maxn],cnt[64],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int k=0;
		while(a[i]>(1<<k))
		{
			if(a[i]&(1<<k))
			{
				cnt[k]++;
			}
			k++;
		}
		//cout<<a[i];for(int i=6;i>=0;i--)cout<<cnt[i]<<' ';cout<<endl;
	}
	//for(int i=6;i>=0;i--)cout<<cnt[i]<<' ';
	for(int j=60;j>=0;j--)
	{
		//cout<<j<<endl;
		if(cnt[j]>=m)
		{
			ans+=(1<<j);
			for(int i=60;i>=0;i--)
			{
				cnt[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				if((a[i]&(1<<j))==0)
				{
					a[i]=0;
				}
				int k=0;
				while(a[i]>(1<<k))
				{
					if(a[i]&(1<<k))
					{
						cnt[k]++;
					}
					k++;
				}
				//cout<<a[i]<<":";for(int i=6;i>=0;i--)cout<<cnt[i]<<' ';cout<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
