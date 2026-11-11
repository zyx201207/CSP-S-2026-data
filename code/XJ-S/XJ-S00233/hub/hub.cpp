#include<bits/stdc++.h>
using namespace std;
int  c,t,a[1000006],n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++)cin>>a[i];
		if(n>=3)cout<<a[3]<<'\n';
		else cout<<a[1]<<'\n';
	}
	return 0; 
}
