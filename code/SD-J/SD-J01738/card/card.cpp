#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e6+5,N=5e6+6;;
ll n,m,pos[N],cnt[N];
vector<ll> a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	a.push_back(0);
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		a.push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		memset(pos,0,sizeof pos);
		vector<ll> now;
		for(int j=i;j<=n;j++)
		{
			if(pos[a[j]]!=0)
			{
				while(now.empty()==0)
				{
					if(now.back()==a[j])
					{
						pos[now.back()]=0;
						now.pop_back();
						break;
					}
					pos[now.back()]=0;
					now.pop_back();
					
				}
			}
			now.push_back(a[j]);
			pos[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(pos[j]!=0)
			{
				cnt[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<cnt[j]<<" ";
	}
	return 0;
}
