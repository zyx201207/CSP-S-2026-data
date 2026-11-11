#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[2000086],minn=1e11,tot,ans;
void dfs(ll l,ll r,ll cnt){
	if(l==r){
		if(cnt<minn){
			minn=cnt;
			tot=1;
		}
		if(cnt==minn) tot++;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			dfs(i,r,cnt+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d; 
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e11;
				tot=0;
				dfs(i,j,0);
				if(tot==3) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

