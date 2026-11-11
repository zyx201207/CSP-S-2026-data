#include <bits/stdc++.h>
using namespace std;
void dfs(int k,long long ans,int ii){
	if(k==m){
		Max=max(ans,Max);
		return;
	}
	if(ans<=Max || ii==n)
	return;
	for(int i=ii+1;i<=n;i++){
		dfs(k+1,ans&a[i],i);
	}
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    return 0;
}

