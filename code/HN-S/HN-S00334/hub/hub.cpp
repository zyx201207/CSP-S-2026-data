#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(t--)
	{
		int n,k,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			ans+=(x+y)/2;
		}
		cout<<ans%n<<"\n";
	}	
	return 0;
}
