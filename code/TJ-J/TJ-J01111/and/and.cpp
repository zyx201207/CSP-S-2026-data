#include<bits/stdc++.h>

using namespace std;
const int N=2e5+10;

int n,m;
int a[N];
int pian,res;
bool vis[N];

void dfs(int cnt,int anss){
	if(cnt==m){
		res=max(res,anss);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(cnt==0)dfs(cnt+1,a[i]);
		else dfs(cnt+1,anss&a[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)pian=a[i];
		else pian&=a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else if(m==n)cout<<pian;
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}else if(m==n-1){
		
	}
	else if(n<=20){
		dfs(0,0);
		cout<<res;
	}
	else cout<<a[n-m+1];
	return 0;
}

