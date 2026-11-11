#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=5e5+5;
ll a[N],ans[N],s[N];
map<ll,ll> mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll l=1,r=0;
	for(int i=1;i<=n;i++)
	{//¾Ö 
//		memset(s,0,sizeof(s));
		mp.clear();
		r=0;
		for(int j=i;j<=n;j++)
		{
			
			mp[a[j]]++;
			if(mp[a[j]]>=2)
			{
				while(s[r]!=a[j]&&r>1)
				{
					mp[s[r]]--;
					r--;
				}
				mp[s[r]]--;
				r--;
			}
			
			r++;
			s[r]=a[j];
		}
		for(int j=1;j<=r;j++)
		{
	//		cout<<s[j]<<" ";
			ans[s[j]]++;
			s[j]=0;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
