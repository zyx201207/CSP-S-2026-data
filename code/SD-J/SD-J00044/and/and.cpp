#include<bits/stdc++.h> 
using namespace std;

int n, m, maxn = -1;
int a[200010];
vector<int> c;
bool used[200010];
int dp[200010];
void dfs(int choosed, int maxnn){
	if(choosed == m){
		maxn = max(maxn, maxnn);
		return;
	}
	for(int i = 1; i <= n; i ++){
		if(used[i]) continue;
		used[i] = true;
		if(choosed == 0) dfs(1,a[i]);
		else 
		dfs(choosed + 1, a[i] & maxnn);
		used[i] = false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i ++){
		scanf("%d",&a[i]);
	} 
	dfs(0,0);
	printf("%d",maxn);
	return 0;
}


//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//Trick||Treat!
