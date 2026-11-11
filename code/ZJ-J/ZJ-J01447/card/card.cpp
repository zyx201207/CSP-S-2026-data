#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using pii=pair<int,int>;
const int N=5e5+10;
int n,m;
int a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	map<int,int>p;
	for(int i=1;i<=n;i++)
	{
		map<int,int>mp;
		mp.clear();
		for(int j=i;j<=n;j++)
		{
			mp[a[j]]++;
			if(mp[a[j]]>1)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[k]==a[j])
					{
						for(int l=k;l<=j-1;l++)
						{
							mp[a[l]]--;
						}
						break;
					}
				}
			}
		}
		for(auto &f:mp)
		{
			if(f.second==0)
			{
				continue;
			}
			p[f.first]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<p[i]<<' '; 
	}
	return 0;	
}