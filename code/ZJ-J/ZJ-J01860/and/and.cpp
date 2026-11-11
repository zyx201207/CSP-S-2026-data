#include<bits/stdc++.h>
using namespace std;
const int inf=200005;
int n,m,a[inf],ans;
bool flag[inf];
void dfs(int lev,int num){
	if(lev>m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			dfs(lev+1,num&a[i]);
			flag[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,INT_MAX);
	cout<<ans;
	return 0;
}
