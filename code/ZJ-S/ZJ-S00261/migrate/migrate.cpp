#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,NN=2e6+5;
int c,T,n,d,a[NN],mn[N][N],ans,cnt,dp[N][N];
void dfs(int st,int at,int ed,int step){
	if(at==ed&&step==mn[st][ed]){
		cnt++;
		return;
	}
	if(cnt>2) return;
	if(step==mn[st][ed]) return;
	if(ceil((double)(a[ed]-a[at])/d)+step>mn[st][ed]) return;
	for(int i=at+1;i<=ed;i++){
		if(a[i]-a[at]<=d){
			dfs(st,i,ed,step+1);
		}else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		if(c<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					mn[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				mn[i][i]=0;
				for(int j=i+1;j<=n;j++){
					int p=lower_bound(a+1,a+1+n,a[j]-d)-a;
					mn[i][j]=mn[i][p]+1;
				}
			}
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					cnt=0;
					dfs(u,u,v,0);
					dp[u][v]=cnt;
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<'\n';
			continue;		
		}
		if(c==11||c==12){
			int diff=a[2]-a[1],x=2*(d/diff)-1;
			if(x<=1){
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+x<=n) ans++;
			}
			cout<<ans<<'\n';	
			continue;		
		}
		cout<<0<<'\n';
	}
	return 0;
}
