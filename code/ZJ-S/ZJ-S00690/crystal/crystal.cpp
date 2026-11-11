#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans;
__int128 sum;
deque<int>q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	q.push_front(1);
	sum+=a[1];
	for(int i=1;i<=n;i++)
	{
		if(!q.empty()&&q.back()<i)
			sum-=a[q.back()],q.pop_back();
		__int128 tot=(__int128)(a[i])*q.size()-sum;
		while(!q.empty()&&q.front()+1<=n&&tot+a[i]-a[q.front()+1]<=m)
			q.push_front(q.front()+1),sum+=a[q.front()],tot=(__int128)(a[i])*q.size()-sum;
		ans=max(ans,(long long)(q.size()));
	}
	cout<<ans;
	return 0;
}
