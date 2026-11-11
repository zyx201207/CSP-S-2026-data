#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,cnt,ans=0;
int a[1000000];
void dfs(int x){
	ans=1;
	if(x>n)return ;
	cnt=m;
	for(int j=x+1;j<=n;j++){
		if(a[j]==a[x])ans++;
		if(a[j]<a[x]){
			if(a[x]-a[j]<=cnt){
				ans++;
				cnt=cnt+a[j]-a[x];
			}
			else{
				maxn=max(maxn,ans);
				dfs(x+1);
				
			}
		}
	}
	maxn=max(maxn,ans);
	dfs(x+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	dfs(1);
	cout<<maxn;
	return 0;
}