#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2000010],n,m,i,ma,ans,x,a[2000010],j,sum;
void check(int step){
	int sum,i;
	sum=-1;
	if(step!=m) return ;
	for(i=1;i<=n;i++)
	  if(f[i])
	    if(sum==-1) ans=a[i];
	    else sum&=a[i];
	ans=max(ans,sum);
}
void dfs(int t,int step){
	if(step>m) return ;
	if(t==n+1){
		check(step);
		return ;
	}
	f[t]=1;
	dfs(t+1,step+1);
	f[t]=0;
	dfs(t+1,step);
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	x=a[1];
	for(i=2;i<=n;i++)
	  x&=a[i];
	if(n<=20) dfs(1,0),cout<<ans;
	else{
		if(m==1) cout<<ma;
		else if(m==n) cout<<x;
		else if(m==2){
			for(i=1;i<=n;i++)
			  for(j=i+1;j<=n;j++)
			    ans=max(ans,(a[i]&a[j]));
			cout<<ans;
		}
		else 
		if(m==n-1){
			for(i=1;i<=n;i++){
				sum=-1;
				for(j=1;j<=n;j++)
				  if(j==i) continue;
				  else if(sum=-1) sum=a[i];
				  else sum&=a[i];
				ans=max(ans,sum);
			}
			cout<<ans;
		}
		else cout<<0;
	}
	return 0;
}
/*
Trick||Treat!
4 2
3 15 12 12
*/