#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=5005,M=2000005;
int cid,_,n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	int m=n/2+2;
	if(k>=n) cout<<0<<'\n';
	else if(k>=m) cout<<1<<'\n';
	else cout<<(m-k+3)/4<<'\n';
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cid>>_;
	while(_--) solve();
	return 0;
}
