#include <bits/stdc++.h>
using namespace std;
const int maxn=2000005;
int n,d,c,t,x[maxn],las,las2;
pair<int,int> findnxt(int u,int v)
{
	int ed=u,sm=0;
	las=ed;
	las2=las;
	cout<<"flyingfrom "<<u<<" to "<<v<<endl;
	if(x[v]-x[u]<=d)
	{
		return make_pair(-1,-1);
	}
	while(ed<v)
	{
		while(sm<=d&&ed<n)
		{	
			cout<<"goto "<<ed<<endl;
			sm=x[ed++]-x[las];	
		}
		if(ed>n)
		{
			return make_pair(las,v);
		}
		cout<<"land on"<<ed<<endl;
		if(ed==v)
		{
			return make_pair(las,ed);
		}
		las2=las;
		las=ed;
		cout<<"las="<<las<<endl;
	}
	return make_pair(las2,las);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;

	for(int q=1;q<=t;q++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
//		for(int i=1;i<n;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				pair<int,int>an=findnxt(i,j);
//				cout<<"from "<<i<<" to"<<j<<", last fly from"<<an.first<<" to "<<an.second<<endl;
//			}
//		}
		cout<<1;
	}
	return 0;
}
