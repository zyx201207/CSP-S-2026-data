#include <bits/stdc++.h>
using namespace std;
string j;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,b[200005];
	string a[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		for(int i=1;i<=b[i];i++)
		{
			j+=a[i];
		}
	}
	cout<<j;
	return 0;
}
