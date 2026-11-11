#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N],dp[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) dp[i]=i;
	for(i=1;i<=m;i++) cout<<dp[i]<<" ";
	cout<<"\n";
	return 0;
}
