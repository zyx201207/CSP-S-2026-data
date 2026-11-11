#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
long long a[200050];
bool flag[200050];//false
void dfs(int now,int cnt){
	if(cnt==m){
		ans=max(ans,now);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]&&(now&a[i])>ans) {
		flag[i]=true;
		dfs(now&a[i],cnt+1);
		flag[i]=false;
	}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		flag[i]=true;
		dfs(a[i],1);
		flag[i]=false;
	}//当前&结果，已选数字个数 
	cout<<ans;
	return 0;
}
