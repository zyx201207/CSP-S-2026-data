#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
ll n,m,a[200005],ans,mx,kmx,jmx,cmx;
ll f[200005][2];//1Ñ¡£¬0²»Ñ¡ 
void dfs(ll x,ll t,ll s){
	if(t+(n-x+1)<m) return;
	if(t==m){
		ans=max(ans,s);
		return;
	}
	if(x==n+1) return;
	if(s==0) dfs(x+1,t+1,a[x]);
	else dfs(x+1,t+1,s&a[x]);
	dfs(x+1,t,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	kmx=a[1];
	for(int i=2;i<=n;i++) kmx&=a[i];
	for(int i=1;i<=n;i++) cmx=max(cmx,kmx&a[i]);
	if(m==1) cout<<mx;
	else if(m==n) cout<<kmx;
	else if(m==n-1) cout<<cmx;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				jmx=max(a[i]&a[j],jmx);
			}
		}
		cout<<jmx;	
	}
	else{
		dfs(1,0,0);
		cout<<ans;	
	}
}
