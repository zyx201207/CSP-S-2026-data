#include<bits/stdc++.h>
using namespace std;
long long a[10001],n,m,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=a[i];
	}
	cout<<s<<endl;
	return 0;
}
