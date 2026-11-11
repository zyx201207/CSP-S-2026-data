//孟梓瑜 SN-J00834 西安市铁一中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=(ll)(2e5+5);
ll ejz[Maxn][35ll];//对于每个数，留够35位存储空间 
bool nume[Maxn];//每个数还在不在 false：在 true：不在   (每个数有没有被裁员) 
ll ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ll n,m,minn=35ll;
	cin>>n>>m;
	for(ll i=1ll;i<=n;i++)
	{
		ll a;
		cin>>a;
		ll idx=30ll;
		for(ll j=a;j;j/=2,idx--)
			ejz[i][idx]=j%(2ll);
		minn=min(minn,idx);
//		cout<<idx<<endl;
	}
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=minn+1;j<=30;j++)
//			cout<<ejz[i][j];
//		cout<<endl;
//	}
	ll cf=30ll-minn-1ll;
	for(ll j=minn+1ll;j<=30ll;j++,cf--)
	{
		ll sum=0ll;
		for(ll i=1;i<=n;i++)
			if(nume[i]==false)//此数没有被裁掉 
				sum+=ejz[i][j];
		if(sum<m)
			continue;
		else//有希望 可以放心裁员 
		{
			ll cy=0ll;
			for(ll i=1;i<=n;i++)
				if(ejz[i][j]==0ll)
					nume[i]=true;
			ans+=pow(2ll,cf);
		}
			
					
			
	}
		
	cout<<ans;
	
	return 0;
}
