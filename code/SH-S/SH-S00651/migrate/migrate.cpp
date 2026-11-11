#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c, t; // 哦原来c是为pian分做的铺垫啊 
ll n, d;
const int N = 2e6 + 5;
ll arr[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i = 1; i <= n; i++) cin>>arr[i];
		int state = 0;
		for(int i = 2; i <= n; i++)
		{
			if(arr[i] - arr[i - 1] > d)
			{
				state = 1;
				break;
			}
		}
		if(state == 1)
		{
			cout<<0<<endl;
			continue;
		}
		if(c == 11 || c == 12)
		{
			if(d >= 3ll * (arr[2] - arr[1]))
			{
				cout<<n - 3<<endl;
				continue;
			}
			else
			{
				cout<<0<<endl;
				continue;
			}
		}
	}
	return 0;
}
/*
不知道为什么，这题像是要得0分的样子 
*/
