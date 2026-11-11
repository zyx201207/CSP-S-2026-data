#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define F first
#define S second

const int MN=2e5+10;
int n,m;
int a[MN];
int ans[MN];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		ans[i]+=ans[i-1];
		cout<<ans[i]<<' ';
	}
	return 0;
}
