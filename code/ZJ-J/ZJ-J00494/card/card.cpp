#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N],cnt[N];
bool f[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=1;x<=n;x++)
	{
		memset(f,false,sizeof(f));
		stack<int> st;
		for(int i=x;i<=n;i++)
		{
			if(!f[a[i]])
			{
				st.push(a[i]);
				f[a[i]]=true;
			}
			else
			{
				while(st.top()!=a[i]) 
				{
					f[st.top()]=false;
					st.pop();
				}
			}
		}
		while(st.size())
		{
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
