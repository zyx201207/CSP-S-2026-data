#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
void dfs(int cnt,int idx,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(idx==n+1)return;
	for(int i=idx;i<=n;i++){
		if(sum==0)dfs(cnt+1,i+1,a[i]);
		else dfs(cnt+1,i+1,sum&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool flag=false;
	for(int i=1;i<=n;i++){
		int x=log2(a[i]+1);
		if(pow(2,x)-1!=a[i]){
			flag=true;
			break;
		}
	}
	if(flag==false){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	dfs(0,1,0);
	cout<<ans;
}