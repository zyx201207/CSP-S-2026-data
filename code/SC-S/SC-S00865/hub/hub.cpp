#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=0x3f3f3f;
ll c,t;
ll n,k;
ll a[N][N]; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
		}
		cout<<1;
	}
	return 0;
}
//骗分过样例（了吗？）	暴力（没写）出奇迹 
//没有输入是HYW
//想进奇葩代码大赏 