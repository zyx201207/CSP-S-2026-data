#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	cout<<n<<m<<a[1];
	return 0;
} 
