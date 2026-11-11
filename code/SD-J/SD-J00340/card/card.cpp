#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
const ll MOD = 998244353;
const ll inf = 9e18;
ll n,m;
ll a[N],b[N];
bool have[N],havest[N];
ll ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(ll i = n;i >= 1;i--)
	{
		if(!have[a[i]])
		{
			stack<ll> st;
			for(ll j = i;j <= n;j++)
			{
				if(havest[a[j]])
				{
					while(!st.empty() && st.top() != a[j])
					{
						havest[st.top()] = false;
						st.pop();
					}
				}
				else
				{
					st.push(a[j]);
					havest[a[j]] = true;
				}
			}
			while(!st.empty())
			{
				ans[st.top()] += b[a[i]];
				st.pop();
			}
			for(ll j = i;j <= n;j++) havest[a[j]] = false;
		}
		have[a[i]] = true;
	}
	for(ll i = 1;i <= m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
