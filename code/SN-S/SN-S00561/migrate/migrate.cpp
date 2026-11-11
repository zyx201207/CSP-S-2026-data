//SN-S00561 liuyuhe gxyzfdzx C
//last dance!
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n,nx[N],f[N][2],g[N][2],vs[N][2];
ll d,id[N],ans;
inline int fc(int i,int j){
	if(j>1) return f[i+j-1][1]+j-1;
	return f[i][j];
}
inline int gc(int i,int j){
	if(j>1) return g[i+j-1][1];
	return g[i][j];
}
inline void dp(int i,int j){
	if(j>1) return dp(i+j-1,1);
	if(vs[i][j]) return;
	vs[i][j]=1;
	if(nx[i+j]==i+j){
		f[i][j]=j+1,g[i][j]=0;
		return;
	}
	if(!j){
		if(nx[i]==nx[i-1]){
			f[i][j]=1,g[i][j]=0;
			return;
		}
		dp(nx[i-1]+1,nx[i]-nx[i-1]-1);
		f[i][j]=fc(nx[i-1]+1,nx[i]-nx[i-1]-1)+1;
		g[i][j]=gc(nx[i-1]+1,nx[i]-nx[i-1]-1);
		return;
	}
	if(nx[i+1]==nx[i-1]){
		f[i][j]=2,g[i][j]=0;
		return;
	}
	if(nx[i+1]==nx[i]){
		dp(nx[i-1]+1,nx[i+1]-nx[i-1]-1);
		f[i][j]=2,g[i][j]=fc(nx[i-1]+1,nx[i+1]-nx[i-1]-1);
		return;
	}
	dp(nx[i]+1,nx[i+1]-nx[i]-1);
	f[i][j]=2+fc(nx[i]+1,nx[i+1]-nx[i]-1);
	g[i][j]=nx[i]-nx[i-1]+gc(nx[i]+1,nx[i+1]-nx[i]-1);
}
inline void solve(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++){
		cin>>id[i];
		for(int j=0;j<2;j++) vs[i][j]=0;
	}
	nx[n]=n;
	for(int i=n-1,j=n;i;i--){
		while(i<j&&id[j]-id[i]>d) j--;
		nx[i]=j;
	}
	for(int i=n;i;i--){
		dp(i,0);
		if(i<n) dp(i,1);
	}
	for(int i=1;i<=n;i++) if(nx[i]!=i) ans+=gc(i+1,nx[i]-i-1);
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
