#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],t[3005],ans[3005];
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)
		{
			t[i]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]!=0)
			{
				while(st.top()!=a[j])
				{
					t[st.top()]--;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				t[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=t[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
