#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,A = 2e30; 
int n,m;
int a[N],f[N];
int ans;
void dfs(int x,int sum,int now){
	if(now + m - x + 1 > n)return;
	if(sum <= ans)return;
	if(x == m){
		ans = max(ans,sum);
//		for(int i = 1;i <= m + 1;i ++)cout << f[i] << ' ';
//		cout << ans << endl;
		return;
	}
	for(int i = now + 1;i <= n;i ++){
		f[x + 1] = i;
		dfs(x + 1,sum & a[i],i);
	}
}
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	} 
	sort(a + 1, a + 1 + n,cmp);
	dfs(0,2e30 - 1,0);
	cout << ans; 
	return 0;
} 
