#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000005],maxi=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxi=max(a[i],maxi);
	}
	cout<<maxi;
	return 0;
}
