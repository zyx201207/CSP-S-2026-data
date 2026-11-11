#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int y[2000005];
int ans,l;
int vis[2000005];
void lu(int x,int cnt){
	if(x>=n){
		l=max(l,cnt);
		return ;
	}
	for(int i=n;i>=1;i--){
		if(abs(y[x]-y[i])<=d) lu(x+i,cnt+1);
	}
}
void shai(int x,int last,int cnt,int h){
	if(cnt>h) return ;
	if(x>=n){
		vis[last]++;
		return ;
	}
	for(int j=1;j<=d;j++){
		shai(x+j,x,cnt+1,h);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		l=0;
		memset(vis,0,sizeof vis);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>y[i];
		}
		lu(1,0);
		shai(1,0,0,l);
		for(int i=1;i<=n;i++){
			ans=max(ans,vis[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

