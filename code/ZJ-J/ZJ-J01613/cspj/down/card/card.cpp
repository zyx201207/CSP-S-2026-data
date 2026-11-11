#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	int e[m+1]={};
	vector<int>v;
	vector<int>a;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	for(int i=1;i<=n;i++)
	{
		a.clear();
		for(int l=i;l<=n;l++)
		{
			//cout<<i<<' '<<l<<' '<<'a'<<endl;
			a.push_back(v[l]);
			for(int p=1;p<v.size()-1;p++)
			{
				if(a[p]==v[l])
				{
				  a.pop_back();
				  while(a[a.size()-1]!=a[l]&&!a.empty())
		  		{
		  			//cout<<"b";
	  				a.pop_back();
	  			}
	  			break;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int p=1;p<v.size()-1;p++)
			{
				if(a[p]==i)
				{
				  e[i]++;
	  			break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<e[i]<<' ';
	}
	return 0;
}
