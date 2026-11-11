#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],vis[200005],max1;
void dfs(ll ans,ll now){
	if(now==m+1){
		max1=max(max1,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(ans&a[i],now+1);
			vis[i]=0;
		}
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    if(m==1){
    	ll maxx=0;
    	for(int i=1;i<=n;i++){
    		maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		ll maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n){
		ll sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(n<=20){
		dfs(1048575,1);
		cout<<max1;
	}
	return 0;
}
