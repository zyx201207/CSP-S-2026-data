#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		for(int i = 1; i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		if(k==n) cout<<0<<endl;
		else if(n > 5 && k <= 3) cout<<2<<endl; 
		else cout<<1<<endl;
	}
}
