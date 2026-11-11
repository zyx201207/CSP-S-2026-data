#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,k;
map<int,int> mp;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mp[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i])cout<<mp[i]<<" ";
	}
	return 0;
}
