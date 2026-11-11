#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans = -1;
long long a[200006];
void dfs(long long x,long long step,long long w){
	if(step>m){
		ans = max(ans,w);
		return;
	}
	for(int i = x;i <= n;i++){
		if(step==1){
			dfs(i+1,step+1,a[i]);
		}
		else{
			long long c = w&a[i];
			dfs(i+1,step+1,c);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,1,0);
	cout << ans;
	return 0;
} 
