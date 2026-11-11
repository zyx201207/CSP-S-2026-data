#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[200005],c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		while(a[i]--) cout<<c[i];
	}
	return 0;
}
