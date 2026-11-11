#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<n/m-1<<"\n";
	}
	return 0;
 } 
