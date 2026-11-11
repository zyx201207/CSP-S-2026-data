#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n,m,a[N];
int dfs(int x,int y){
	if(n - x + y + 1 < m)return 0;
	if(x == n)return a[x];
	if(y == m)return 1073741823;
	return max(dfs(x + 1,y),a[x] & dfs(x + 1,y + 1));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%lld",&a[i]);
	printf("%lld",dfs(1,0));
	return 0;
}
/*
1

4 2
3 15 12 12

12
*
2

5 3
31 3 1 15 7

7
*/
