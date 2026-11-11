#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans = 0;

void dfs(int num,int first,int res){
	if(n - first+1+num < m)return;
	for(int i = first;i<=n;i++){
		if(num == m){
			ans = max(ans,res&a[i]);
			return;
		}
		if(num == 1)dfs(num+1,i+1,a[i]);
		else dfs(num+1,i+1,res&a[i]);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1,1,0);
	cout << ans;
	return 0;
}