#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
int vis[N];
int ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cout<<0<<" ";
	return 0;
}

