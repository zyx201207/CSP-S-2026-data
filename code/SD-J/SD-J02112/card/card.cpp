#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],ans[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int>v; 
		for(int j=i;j<=n;j++)
		{
			bool f=0;
			v.push_back(a[j]);
			for(int k=0;k<v.size()-1;k++)
			{
				if(v[k]==a[j])f=1;
				if(f)v[k]=0;
			}
		}
		for(int c:v)ans[c]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
