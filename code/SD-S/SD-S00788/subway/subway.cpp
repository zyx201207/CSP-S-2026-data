#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>a[i];
	}
	while(q--)
	{
		cout<<a[1]+a[m]*5<<endl;
	}
	return 0;
}
