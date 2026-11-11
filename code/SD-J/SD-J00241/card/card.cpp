#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int sum[N],a[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[a[i]]=i;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
