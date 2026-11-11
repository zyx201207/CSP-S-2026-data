#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N2=2e6+5,N=5005;
ll opt,t;
ll x[N2];
bool ck[N][N],vis[N];
int sumck[N][N];
inline void subx(){
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(d/(x[2]-x[1])<=1)cout<<"0\n";
		else cout<<max(0ll,n-2*(d/(x[2]-x[1]))+1)<<'\n';
	}
	return ;
}
inline void sub2(){
	while(t--){
		memset(ck,0,sizeof ck);
		memset(vis,0,sizeof vis);
		ll n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int t=1;t<=n;t++)
			if(x[i+2*t+1]-x[i]>d&&x[i+t+1]-x[i]<=d&&x[i+2*t+1]-x[i+t]<=d)ck[i][t]=1;
		}
		for(int i=1;i<=n;i++){
			for(int t=1;t<=n;t++){
				sumck[i][t]=sumck[i-1][t]+ck[i][t];
				if(x[i]-x[i-1]>d)sumck[i][t]+=2,vis[i]=vis[i+1]=vis[i+2]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int t=1;t<=n;t++)
			for(int j=1+2*t+i;j<=n;j++){
				if((sumck[j-2*t-1][t]-sumck[i-1][t]==1||(vis[i]&&sumck[j-2*t-1][t]-sumck[i-1][t]==3))&&!vis[j])ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<sumck[i]<<' ';
//		}
		cout<<ans<<'\n';
	}
	return ;
}
inline void init(){
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);init();
	cin>>opt>>t;
	if(opt==11||opt==12){
		subx();
		return 0;
	}
	sub2();
	return 0;
}
