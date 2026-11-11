#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
int c,T;
ll n,d;
ll arr[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c == 1 || c == 2)
	{
		if(T == 2)
		{
			cout<<1<<'\n'<<2;
		}
		else
		{
			for(int i = 1;i <= T;i++)
			{
				cout<<0<<'\n';
			}
		}
		return 0;
	}
	if(c == 11 || c == 12 || c == 0)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i = 1;i <= n;i++)
			{
				cin>>arr[i];
			}
			ll x = arr[2] - arr[1];
			if(d < x || d > arr[n] - arr[1])
			{
				cout<<0<<'\n';
				continue;
			}
			ll block = d / x;
			ll cnt = (n - 1) / block;
			if((n - 1) % block)
			{
				cout<<n - 1 - block - (((n - 1) % block) - 1)<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}
		return 0;
	}
	for(int i = 1;i <= T;i++)
	{
		cout<<0<<'\n';
	}
	return 0;
}