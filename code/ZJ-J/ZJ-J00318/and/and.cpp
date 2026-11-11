#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=2*1e5+5;
ll n,m,a[num],ans;
bool vis[num];
void dfs(ll step,ll value){
	if(step==m){
		ans=max(ans,value);
		return;
	}
	for(ll i=0;i<n;++i){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,(value&a[i]));
			vis[i]=0;
		}	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof vis);
	scanf("%lld%lld",&n,&m);
	if(n<=20){
		for(ll i=0;i<n;++i)
			scanf("%lld",&a[i]);
		for(ll i=0;i<n;++i){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
	}
	else if(m==n){
		for(ll i=0;i<n;++i){
			cin>>a[i];
			if(i==0){
				ans=a[i];
			}
			ans&=a[i];
		}
	}
	else if(m==1){
		for(ll i=0;i<n;++i){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(ll i=0;i<n;++i)
			cin>>a[i];
		for(ll i=0;i<n-1;++i){
			for(ll j=i+1;j<n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		for(ll i=0;i<n;++i)
			scanf("%lld",&a[i]);
		for(ll i=0;i<n;++i){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}