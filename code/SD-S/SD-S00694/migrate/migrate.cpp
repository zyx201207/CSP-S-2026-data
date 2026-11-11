#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305,INF=4e18,N2=2e6+5;
int c,T,n,d,ans;
int a[N],w[N][N],cnt[N][N],a2[N2];
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a2[i]; 
	d=d/(a2[2]-a2[1]);
	if(d<=1){
		cout<<"0\n";
		return;
	}
	cout<<max(0ll,n+1-d*2)<<'\n';
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j){
				w[i][i]=0,cnt[i][j]=0;
				continue;
			}
			if(abs(a[j]-a[i])<=d){
				w[i][j]=1;
				cnt[i][j]=1;
			}
			else{
				w[i][j]=INF;
				cnt[i][j]=0;
			}
		}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				if(w[i][j]==w[i][k]+w[k][j]) cnt[i][j]=cnt[i][j]+cnt[i][k]*cnt[k][j];
				else if(w[i][j]>w[i][k]+w[k][j]) cnt[i][j]=cnt[i][k]*cnt[k][j],w[i][j]=w[i][k]+w[k][j];
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	cout<<ans<<'\n'; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>T;
	if(c>=11&&c<=12){
		while(T--) solve1();
		return 0;
	}
	while(T--) solve();
	return 0;
} 
