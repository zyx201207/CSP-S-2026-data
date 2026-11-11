#include<bits/stdc++.h>
using namespace std;
stack<int> st;
long a[500099],n,m,s[500099],i,s1[500099],j,t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(s1[a[j]]==0)
			{
				st.push(a[j]);
				s1[a[j]]+=1;
			}
			else
			{
				while(a[j]!=st.top())
				{
					
					if(a[j]==st.top()) break;
					else
					{
						s1[st.top()]=0;
						st.pop();
					}
				}
			}
		}
		while(!st.empty())
		{
			s[st.top()]++;
			st.pop();
		} 
		memset(s1,0,sizeof(s1));
	}
	for(i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
