#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],mx;
ll ans[300005];
ll cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<ll>st;
	for(ll i=1;i<=n;i++)
	{
		memset(cnt,false,sizeof(cnt));
		for(ll j=i;j<=n;j++)
		{
			if(cnt[a[j]]>0)
			{
				while(st.top()!=a[j])
				{
					cnt[st.top()]--;
					st.pop();
				}
			}
			else
			{
				cnt[a[j]]++;
				st.push(a[j]);
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
