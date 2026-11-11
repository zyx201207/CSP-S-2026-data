#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,vis[200005],a[200005],q[200005],h[200005],f;
void dfs(int dep,int x){
	if(dep==m+1){
		long long s=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				if(s==0) s=a[i];
				else s=s&a[i];
			}
		}
		ans=max(ans,s);
		return;
	}
	for(int i=x;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(dep+1,i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    //	ma=max(a[i],ma);
    	if(i==1) q[i]=a[i];
    	else q[i]=q[i-1]&a[i];
    	if(a[i]!=a[i-1]) f=1;
	}
	for(int i=n;i>=1;i--){
		if(i==n) h[n]=a[i];
		else h[i]=h[i+1]&a[i];
	}
    if(m==n) cout<<q[n];
	else if(m==n-1){
	   for(int i=1;i<=n;i++){
	   	   if(i==1) ans=max(ans,h[2]);
	   	   else if(i==n) ans=max(ans,q[n-1]);
	   	   else ans=max(ans,q[i-1]&h[i+1]);
	   }
	   cout<<ans;	
	}else if(f==0){
		cout<<a[1];
	}else{
		dfs(1,1);
		cout<<ans;
	}
	return 0;
}
