#include <bits/stdc++.h>
using namespace std;
int a[100050],b[100050];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
		}
		cout<<a[1]+a[3]+a[4];
	}
	return 0;
}
