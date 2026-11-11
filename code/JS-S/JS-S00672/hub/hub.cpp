#include<iostream>
using namespace std;
#define ll long long
int c,t;
int n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)cin>>u>>v;
		if(n==k)cout<<"0\n";
		else if(k>=n/2)cout<<"1\n";
		else if(k>1)cout<<(n/2+5-k)/4<<'\n';
		else cout<<(n/2+2)/2;
	}
	return 0;
}
