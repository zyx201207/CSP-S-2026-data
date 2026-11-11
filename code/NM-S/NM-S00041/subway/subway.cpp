#include <bits\stdc++.h> 
using namespace std;
#define ll long long
ll c,d,n,m,q;
ll k,x[500050],y[500050];
struct link{
	ll to,we;
}ltr;
struct node{
	ll w;
	vector<link> to;
}tr;
bool cmp(link a,link b)
{
	return a.we>b.we;
}
vector<node> nodes;
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		ll x;
		cin>>x;
		tr.w=x;
		nodes.push_back(tr);
	}
	for(int i=1;i<=n;i++)
	{
		
		cin>>k;
		for(int j=1;j<=k;j++)cin>>x[j]>>y[j];
		for(int j=2;j<=k;j++)
		{
			for(int h=1;h<j;h++)
			{
				ltr.to=x[h];ltr.we=y[j]+y[h];
				nodes[x[j]].to.push_back(ltr);
				ltr.to=x[j];
				nodes[x[h]].to.push_back(ltr);
			}
		 } 
	}
	for(int i=1;i<=m;i++)
	{
		sort(nodes[i].to.begin(),nodes[i].to.end()+1,cmp);
	}
	cout<<"666";
	return 0;
}
/*
 0 2 5 20 2
4 1 9 2 5
3 1 5 2  7 4 6
3 2 3 3 4 5 7
*/
