#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,a[200100];
void dfs(ll x,ll s,ll w){
	if(x>m){
		ans=max(ans,s);
		return;
	}
	for(int i=w+1;i<=n;i++){
		dfs(x+1,s&a[i],i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		dfs(2,a[i],i);
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
answer 12

3  1+2
15 1+2+4+8
12 4+8
12 4+8


5 3
31 3 1 15 7
answer 7

31 1+2+4+8+16
3  1+2
1  1
15 1+2+4+8
7  1+2+4


*/
