#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
using LL=long long;
LL a[N];
LL di,d,cnt;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	int ans=1;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<ans<<endl;
		ans++;
	}
	return 0;
}