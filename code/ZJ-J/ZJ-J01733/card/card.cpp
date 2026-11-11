#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],last[N],ans[N];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],last[a[i]]=i;

	for(int l=1;l<=n;l++)
	{
		vector<int>card;
		for(int i=l;i<=n;i++)
		{
			card.push_back(a[i]);
			i=last[a[i]];	
		}	
		
		for(auto it:card)
		{
			ans[it]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}	
//4 3
//1 2 1 3
//10 3
//3 1 2 1 3 2 3 1 2 1
