//草木逢春，慧如恒沙。神爱世人，妲门永存！
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=5e5+10.27;
ll n,a[2][maxn],m,ans;
ll l=0,r=maxn;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[0][i];
		//a[1][i]=a[1][i-1]+a[0][i];
	}
	sort(a[0]+1,a[0]+n+1);
	for(int i=1;i<=n;i++)
	{
		//cin>>a[0][i];
		a[1][i]=a[1][i-1]+a[0][i];
	}
	
	while(l<=r)
	{
		ll mid=l+((r-l)>>1);
		//mid=3846;
		bool flag=0;
		
		//printf("ans:%d,l:%d,r:%d,mid:%d\n",ans,l,r,mid);
		for(int i=1;i+mid-1<=n;i++)
		{
			if((a[0][i+mid-1]*mid-(a[1][i+mid-1]-a[1][i-1]))<=m)
			{
				flag=1;
				//cout<<i;for(int j=0;j<mid;j++)cout<<a[0][i+]
				break;
			}
		}
		
		if(flag)//check(mid)
		{
			ans=mid;l=mid+1;
		}
		else
		{
			r=mid-1;	
		}
		//printf("ans:%d,l:%d,r:%d,mid:%d\n",ans,l,r,mid);break;
	}
	
	cout<<ans;
}	