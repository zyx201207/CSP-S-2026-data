#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,m,a[MAXN],pos[MAXN],cnt[MAXN],f[MAXN];
bool flag=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
			flag=false;
	}
	if(flag==true)
	{
		for(int i=1;i<=n;i++)
			pos[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<pos[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(a[k]==a[j])
				{
					while(st.size()>0)
					{
						int x=st.top();
						if(x==a[k])
						{
							st.pop();
							break;
						}
						st.pop();
					}
				}
			}
			st.push(a[j]);
		}
		while(!st.empty())
		{
			int x=st.top();
			cnt[x]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
