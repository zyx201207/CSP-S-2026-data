#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+5;
const int M=2e6+5;
int C,t;
int n,d;
int ans;
int a[M];
int nxt[M];
int f[N][N];
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&a[i]+d>=a[j+1]) j++;
		nxt[i]=j;
	}
	if(C==11||C==12){
		if(nxt[1]==1||nxt[1]==2||nxt[1]==n){
			cout<<0<<"\n";
			return ;
		}
		for(int i=1;i<=n;i++){
			ans++;
			if(nxt[nxt[i-1]]==n) break;
		}
		cout<<ans<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) f[i][j]=1e9;
	for(int i=1;i<=n;i++){
		int x=i;
		for(;x!=nxt[x];x=nxt[x]) f[i][nxt[x]]=f[i][x]+1;
		for(int j=x;j>i;j--) if(f[i][j]<f[i][j-1]) f[i][j-1]=f[i][j];
	}
	for(int i=1;i<=n;i++){
		int x=i;
		for(;x!=nxt[x];x=nxt[x]) f[i][nxt[x]]=f[i][x]+1;
		for(int j=nxt[i]+1;j<=n;j++){
			int sum=0;
			for(int k=i+1;k<j;k++) if(f[i][k]+f[k][j]==f[i][j]) sum++;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<sum<<"\n";
			if(sum==f[i][j]) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>t;
	while(t--) solve();
}
/*
11 1
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987
*/
