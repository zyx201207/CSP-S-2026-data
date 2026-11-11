#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,ans;
queue<ll> q;
ll a[N],m,sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		sum+=a[i];
		while(!q.empty()&&a[i]*(int)q.size()-sum>m)
		  sum-=q.front(),q.pop();
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}