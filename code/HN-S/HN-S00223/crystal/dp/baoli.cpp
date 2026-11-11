#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500005],ta[500005];
void dfs(int x,int cnt){
	if(cnt>m)return;
	if(x>n){
		for(int i=1;i<=n;i++)ta[i]=a[i];
		sort(ta+1,ta+n+1);
		int len=0,cnt;
		for(int i=1;i<=n;i++){
			if(ta[i]==ta[i-1])len++;
			else{
				ans=max(ans,len);
				len=1;
			}
		}
		ans=max(len,ans);
		return;
	}
	for(int i=0;i<=m;i++){
		a[x]+=i;
		dfs(x+1,cnt+i);
		a[x]-=i;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("baoli.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7*/
