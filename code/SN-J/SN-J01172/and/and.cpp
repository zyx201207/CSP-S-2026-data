#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,m,a[200015],max_=0;
void dfs(long long step,long long cnt,long long sum){
	if(step>=m){
		max_=max(max_,sum);
		return;
	}
	dfs(step,cnt+1,sum);
	dfs(step+1,cnt+1,sum&a[cnt]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(0,1,a[i]);
	}
	cout << max_;
	return 0;
}
