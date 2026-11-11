#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=3*1e5+10;
int a[N];
int tot[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		unordered_map<int,int> mp;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]==0) mp[a[j]]=j;
			if(mp[a[j]]!=0)
			{
				int l=mp[a[j]];
				for(int k=l;k<j;k++)
				{
					mp.erase(a[k]);
				}
				mp[a[j]]=j;
			}
		 } 
		for(auto i:mp)
		{
			tot[i.first]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tot[i]<<' ';
	}
	return 0;
}
