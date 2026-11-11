#include<bits/stdc++.h>
using namespace std;
int n,m;
int aa[500005];
bool la[300005];
int s[300005];
stack<int> st; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(!st.empty())
		{
			st.pop();
		}
		for(int j=i;j<=n;j++)
		{
			if(la[aa[j]])
			{
				while(st.top()!=aa[j])
				{
					la[st.top()]=0;
					st.pop();
				}
			}
			else
			{
				st.push(aa[j]);
				la[aa[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(la[j])
			{
				s[j]++;
				la[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
