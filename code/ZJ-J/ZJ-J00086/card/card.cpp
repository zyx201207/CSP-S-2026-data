#include<bits/stdc++.h>
using namespace std;
int a[500005],l[300005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//if(n<=5000)
  //{
		for(int i=1;i<=n;i++)
		{
			stack<int>st;
			for(int j=1;j<=m;j++)
			{
				l[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(l[a[j]]==0)
				{
					st.push(a[j]);
					l[a[j]]=j;
				}
				else
				{
					while(st.top()!=a[j])
					{
						l[st.top()]=0;
						st.pop();
					}
					l[a[j]]=j;
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
  //}
/*	else
	{
		stack<int>st;
		for(int i=n;i>=1;i--)
		{
			if(l[a[i]]==0)
			{
				st.push(a[i]);
				l[a[i]]=i;
			}
			else
			{
				while(st.size()&&st.top()!=a[i])
				{
					l[st.top()]=0;
					st.pop();
				}
				l[a[i]]=i;
			}
			stack<int>st1;
			while(st.size())
			{
				cnt[st.top()]++;
				st1.push(st.top());
				st.pop();
			}
			while(st1.size())
			{
				st.push(st1.top());
				st1.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	}*/
	return 0;
}
