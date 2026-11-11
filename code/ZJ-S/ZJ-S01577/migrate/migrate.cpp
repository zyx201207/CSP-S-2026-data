#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,x[15],mn,ans=0,cnt=0;
void dfs(int now,int to,int dis){
	if(now==to){
		mn=min(mn,dis);
		return;
	}
	for(int i=now+1;i<=to;i++){
		if(x[i]-x[now]<=d){
			dfs(i,to,dis+1);
		}
	}
}
void dfs2(int now,int to,int dis){
	if(now==to){
		if(dis==mn)cnt++;
		return;
	}
	for(int i=now+1;i<=to;i++){
		if(x[i]-x[now]<=d){
			dfs2(i,to,dis+1);
		}
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
	    for(int i=1;i<=n;i++){
	    	cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mn=INT_MAX;
				cnt=0;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}

