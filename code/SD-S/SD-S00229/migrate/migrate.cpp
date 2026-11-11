#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=303;
int c,t,n;
ll mi[N][N],sima[N],dp[N][N];
ll d,x[N],ans=0,cnt=0;
void dfs(int s,int u,int f,int step){
	if(u==f){
		if(step==mi[s][f])cnt++;
		//cout << s << ' ' << f;
		return;
	}
	if(u>f) return;
	if(step>mi[s][f]) return;
	for(int i=1;i<=sima[u];i++){
		dfs(s,u+i,f,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(mi,0,sizeof(mi));
		memset(sima,0,sizeof(sima));
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		int j=n;
		for(int i=n-1;i>=1;i--){
			while(x[j]-x[i]>d&&j>i){
				j--;
			}
			sima[i]=j-i;
			
		}
		for(int i=n;i>1;i--){
			for(int j=i-1;j>=1;j--){
				if(sima[j]>=i-j){
					mi[j][i]=1;
				}else if(mi[j+sima[j]][i]){
					mi[j][i]=1+mi[j+sima[j]][i];
				}else{
					mi[j][i]=0;
				}
				
			}
			if(mi[i-1][i]){
				dp[i-1][i]=1;
			}else{
				dp[i-1][i]=0;
			}
		}
		if(c==11||c==12){
			ll sum=(sima[1]-1)*(n-1-2*sima[1]+1);
			cout << sum << '\n';
		}else{
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					cnt=0;
					dfs(j,j,i,0);
					if(cnt==2) ans++;
				}
			}
			cout << ans << '\n';
		}
		
	}
	return 0;
}
