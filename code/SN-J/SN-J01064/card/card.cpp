#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,x,a[100005];
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<x<<" "<<n-x<<" "<<n;
	return 0;
}
