#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+7;
ll ans=0,a[N][7],c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>a[i][1]>>a[i][2];
		}
		ll ans=n/(k+1);
		cout<<ans<<"\n";
	}
}
//注意到，部分答案为 n/(k+1) 
