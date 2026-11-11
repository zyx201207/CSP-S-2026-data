#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans,ma,s,a[200010];
void dfs(long long t,long long g,long long s){
	if(s<ans)return ;
	if(g>m)return ;
	if(g==m){ans=max(ans,s);return ;}
	if(t>n)return ;
	if(s==0)dfs(t+1,g+1,a[t]);
	else dfs(t+1,g+1,s&a[t]);
	dfs(t+1,g,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]),s&=a[i];
	if(m==1)cout<<ma,exit(0);
	if(m==n)cout<<s,exit(0);
	if(m==2){
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;exit(0);
	}
	if(m==n-1){
		for(i=1;i<=n;i++)ans=max(ans,s&a[i]);
		cout<<ans;exit(0);
	}
	dfs(1,0,0);cout<<ans;
	return 0;
}

