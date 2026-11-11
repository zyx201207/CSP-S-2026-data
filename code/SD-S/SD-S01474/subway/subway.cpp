#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e5+10,INF=3e18+10;
int x,y,n,m,w,v;
int mx,mn;
int a[N];
int ans = 0, sum = 0;
signed main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin >> mn >> n >> m >> w >> v;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		ans+=x;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		for(int j=1;j<=x;j++)
		{
			cin >> sum;
			ans+=sum;
		}
	}
	for(int i=1;i<=v;i++)
	{
		cin >>x>>sum;
	}
	cout << ans;
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6 
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

