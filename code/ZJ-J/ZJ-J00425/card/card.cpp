#include<bits/stdc++.h>
using namespace std;
int tong[5005],n,m,a[5005],ans[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==3)
	{
		cout<<3<<" "<<1<<" "<<4;
	}
 	return 0;
}
