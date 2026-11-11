#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int x[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	cout<<x[n-m+1];
	return 0;
}