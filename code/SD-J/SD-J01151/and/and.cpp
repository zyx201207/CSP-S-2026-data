#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
priority_queue< int,vector<int>,greater<int> >q; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	while(n--)
	{
		int temp;
		cin>>temp;
		q.push(temp);
		while(q.size()>m)q.pop();
	}
	ans=q.top();
	q.pop();
	for(int i=1;i<=m-1;i++)
	{
		int temp=q.top();
		q.pop();
		ans=ans&temp;
	}
	cout<<ans;
	return 0;
}
