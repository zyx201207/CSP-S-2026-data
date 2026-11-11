#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
const ll inf = 0x3f3f3f3f;
int c;
ll n,m,d,q;
ll arr[N];
int x,y,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
	{
		cin>>arr[i];
	}
	for(int i = 1;i <= n;i++)
	{
		ll flag;
		cin>>flag;
		for(int j = 1;j <= flag;j++)
		{
			cin>>a>>b;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>x>>y;
		cout<<arr[x] + arr[y] + 2 * a<<'\n';
	}
	return 0;
}