#include<bits/stdc++.h>
using namespace std;
int a[10001010];
stack<int>st;
map<int,int>mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			st.push(a[j]);
			for(int k=1;k<=j-i+1;k++)
			{
				if(a[k]==a[j])
				{
					for(int h=1;h<=j-k+1;h++)
					{
						st.pop();
					}
					break;
				}
			}
		}
		for(int j=1;j<=st.top();j++)
		{
			mp[st.top()]++;
			st.pop();
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<" ";
	}
	return 0;
	
}
