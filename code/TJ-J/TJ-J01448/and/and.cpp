#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int N = 200005;
long long a[N];
bool vis[N]; 
long long ans = -1;

bool cmp(int x,int y){
	return x > y;
}

void dfs(long long sum,int step){
	if(step >= m) {
		ans = max(ans,sum);
		return;
	}
	for(int j = 1; j <= n; j ++){
		if(vis[j] == 0){
			vis[j] = 1;
			dfs(sum & a[j],step + 1);
			vis[j] = 0;
		}
	}
}

void solve1(){
	for(int i = 1; i <= n; i ++){
		vis[i] = 1;
		dfs(a[i],1);
		vis[i] = 0;
	}
}

void solve2(){
	sort(a+1,a+1+n,cmp);
	ans = a[1];
	for(int i = 2; i <= m; i ++){
		ans = ans & a[i];
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(n <= 2000){
		solve1();
	}
	else solve2();
	
	cout << ans;
	return 0;
} 
