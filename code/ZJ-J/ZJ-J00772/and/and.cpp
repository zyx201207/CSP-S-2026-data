#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m;
long long a[MAXN];
long long ans=-1;
int cnt;
bool vis[MAXN];
void dfs(int step,long long cnt){
	if(step==m+1){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(step==1){
				dfs(step+1,a[i]);
			}
			else{
				dfs(step+1,cnt&a[i]);
			}
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}