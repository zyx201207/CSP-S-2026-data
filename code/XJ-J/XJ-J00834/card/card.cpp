#include<bits/stdc++.h> 
using namespace std;
vector<int> v;
const int N=3e5+2;
int k[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			if(v[v.size()-1]==a[j]) v.pop_back();
			v.push_back(a[j]);
		}
		for(int l=0;l<v.size();l++) k[v[l]]++;
	    while(!v.empty()) v.pop_back();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<k[i]<<" ";
	}
	return 0;
}
