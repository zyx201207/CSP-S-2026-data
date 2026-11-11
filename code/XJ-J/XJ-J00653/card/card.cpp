#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,a[1000005],ans[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<long long int>st;
	set<long long int>s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		s.clear();
		for(j=i;j<=n;j++)
		{
			if(s.count(a[j])==1)
			{
				while(st.top()!=a[j])
				{
					s.erase(st.top());
					st.pop();
				}
			}
			else
			{
				s.insert(a[j]);
				st.push(a[j]);
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
