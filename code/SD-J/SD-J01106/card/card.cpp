#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100020],b[100020];
vector<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		//b.memset(b,0,sizeof(b));
		q.clear();
		for(int j=0;j<n;j++)
		{
			if(find(q.begin(),q.end(),a[i])!=q.end())
			{
				
				while(q.back()!=a[i])
					q.pop_back();
				q.pop_back();	
				
			}
			else 
			{
				q.push_back(a[i]);
			}
			for (int o=0;o<q.size();o++)
				b[q[o]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	
	
}
