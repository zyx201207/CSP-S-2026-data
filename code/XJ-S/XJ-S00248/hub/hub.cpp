#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int x=n,y=n%(k*10);
		while((x/2)-(y/2)>=k*10)
		{
			x/=2;
			y/=2;
		}
		cout<<x-y+1<<'\n';
	}
	return 0;
}

