#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt=-1,tnt;
bool cmp(int x,int y){
	return y>x;
}
void dfs(int t,int sum,int ans){
	if(t==n){
		if(sum==m) cnt=max(cnt,ans);
		return ;
	}
	int k=t+1;
	if(ans=-1){
		dfs(k,sum+1,a[k]);
		dfs(k,sum,-1);
	}else{
		dfs(k,sum+1,ans&a[k]);
		dfs(k,sum,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=20){
		dfs(0,0,-1);
	}
	else{
		tnt=a[1];
		for(int i=2;i<=m;i++){
			tnt=tnt&a[i];
		}
	}
	cout<<max(tnt,cnt);
	return 0;
}