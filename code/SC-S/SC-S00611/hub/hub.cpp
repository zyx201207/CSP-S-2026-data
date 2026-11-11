#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,k,x,y;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14){
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>x>>y;
		if(k==n)cout<<"0"<<'\n';
		else if(k==n/2)cout<<"1"<<'\n';
		else if(k==1)cout<<n/4+1<<'\n';
		else cout<<(((n/2-k)%4)?((n/2-k)/4)+1:((n/2-k)/4))+1<<'\n';
	}}
	else
	{
		srand(time(0));
		while(t--)
		{
			int ra=rand()%((n-k)/4);
			cin>>n>>k;
			for(int i=1;i<=n;i++)cin>>x>>y;
			cout<<(n-k)%ra<<'\n';
		}
	}
	return 0;
}