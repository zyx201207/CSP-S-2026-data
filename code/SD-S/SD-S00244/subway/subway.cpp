#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
const ll MOD = 998244353;
const ll inf = 9e18;
ll c,n,m,d,q;
ll w[N],k[510];
ll a[510][20010],t[510][20010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(ll i = 1;i <= m;i++)
	{
		cin>>w[i];
	}
	for(ll i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(ll j = 1;j <= k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		ll start,end;
		cin>>start>>end;
		if(start == end) cout<<"0\n";
		else cout<<w[start] + w[end]<<"\n";
	}
	
	return 0;
}
