#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
stack<ll>st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<ll>a(m+5),b(m+5),s(n+5);
	for(ll i=1;i<=n;i++)cin>>s[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll k=i;k<=n;k++)
		{
			if(b[s[k]]==0)
			{
				st.push(s[k]);
				b[s[k]]=k;
			}
			else
			{
				for(ll j=b[s[k]];j<k;j++)
				{
					b[st.top()]=0;
					st.pop();
				}
				b[s[k]]=k;
				st.push(s[k]);
			}
		}
		while(!st.empty())
		{
			a[st.top()]++;
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++)cout<<a[i]<<' ';
	return 0;
}
