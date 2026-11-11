#include <bits/stdc++.h>
using namespace std;
int k[2000006];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1; i <=t; i++)
	{
		int a,b;
		cin>>a>>b;
		for(int j = 1; j<a; j++)
		{
			int x,y;
			cin>>x>>y;
			k[j]=y-x;
		}
		sort(k+1,k+a);
		cout<<k[b]<<endl;
	}
	return 0;
}
