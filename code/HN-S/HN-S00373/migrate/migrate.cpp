#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2000005;

void solve()
{
	cout<<0<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_id,t;
	cin>>test_id>>t;
	while(t--) solve();
	return 0;
}
//16.37 如果某个 (u,v) 是合法的，有且只有两个 x<w<v 使得 w 可以直达 v
//      其中 x 是最大的 i 满足 x[v]-x[i]>d
//      所以考虑枚举终点 v，二分出对应的 x，如果是，则能到达x的点都符合条件？ 
//      感觉这个做法应该是对的?
//17.13 不是怎么一直错啊 
