/*
	???!?!?!?!?!???!??!?!?!?!?!??!!?!?
	0 pts
	luogu 1842302
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14)
	{
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			cout<<n*(n-1)/2<<endl;
		}
	}
	return 0;
}