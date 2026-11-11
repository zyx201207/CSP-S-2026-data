#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int zp[500005];
int u[500005];
int cnt[300005];
stack <int> st;
void yx(int l)
{
	for(int i=1;i<=n;i++)
	{
		u[zp[i]]=0;
	}
	for(int i=l;i<=n;i++)
	{
		if(u[zp[i]]!=0)
		{
			while(st.top()!=zp[i]&&!st.empty())
				st.pop();
		}
		st.push(zp[i]);
		u[zp[i]]=1;
	}
	while(!st.empty())
	{
		cnt[st.top()]++;
		st.pop();
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>zp[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]!=0)
			cout<<cnt[i]<<" "; 
	}
	return 0;
} 
