#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<rand()%10+1<<"\n";
	}
	
	
	return 0;
}