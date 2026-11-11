#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1,M=3e5+1;
int a[N],card[M];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	map<int,int>ma;
	stack<int>st;
	for(int i=1; i<=n; i++)
	{
		cin>>card[i];
		ma[card[i]]=0;
	}

	for(int j=1; j<=n; j++)
	{
		for(int i=j; i<=n; i++)
		{
			st.push(card[i]);
			ma[card[i]]++;
			if(ma[card[i]]>1)
			{
				st.pop();
				while(1)
				{
					ma[st.top()]--;
					if(st.top()==card[i])break;
					st.pop();
				}
			}
		}
		while (!st.empty())
		{
			a[st.top()]++;
			ma[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}
