#include<bits/stdc++.h>
using namespace std;
#define ll long long 
typedef pair<ll,ll> PI;
ll c,t,n,d,ans,num,dis[1000010],minn;
void dfs(ll x,ll endn,ll sta){
	if(x==endn){
		if(sta<minn){
		num=1;	
		minn=sta;
		}
		else if(sta==minn)num++;
		return;
	}
	for(int i=1;dis[x+i]-dis[x]<=d&&x+i<=n;i++){
		dfs(x+i,endn,sta+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>dis[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e9;
				num=0;
				dfs(i,j,0);
				if(num==2){
				
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
