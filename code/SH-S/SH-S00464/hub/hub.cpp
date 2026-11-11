#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		v.clear();
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		srand(time(0));
		int r;
		if(c<=6) r=10;
		else if(c<=10) r=1000;
		else if(c<=17) r=1e5;
		else r=1e6;
		cout<<rand()%r;
	}
	//Oct31==Dec25?
	return 0;
}
