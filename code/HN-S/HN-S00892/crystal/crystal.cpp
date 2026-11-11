#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,k,a[N],ans=1;
queue<int>q;
/*
作者: HN-S00892 wbw_121124(luogu uid 792595)
> g++: error: cannot specify -static with -fsanitize=address
...
你们猜我今年能过T1吗？
我讨厌小 W :-(

小
@
w
@
在
@
发
@
电

cute zrr
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		k-=(a[i]-a[i-1])*q.size();
		while(!q.empty()&&k<0)
		{
			k+=a[i]-a[q.front()];
			q.pop();
		}
		q.push(i);
		ans=max<int>(ans,q.size());
	}
	cout<<ans;
	return 0;
}