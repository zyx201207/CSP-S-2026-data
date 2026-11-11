//许喆涵 SN-J00784 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long a[200007];
bool vis[20007];
void dfs(long long sum, long long step){
	if(step==m){
		ans=max(ans,sum);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(sum&a[i],step++);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	dfs(1073741823,0);
	cout << ans;
	return 0;
}
