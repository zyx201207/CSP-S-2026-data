#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x[500009],js[509],js2,dp[2009][2009],l,p[3][500009],a[3][500009],f[500009],pp[500009],jss,zx,ff[500009];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	js2=m;
	for(int i=1;i<=m;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		cin>>js[i];
		if(c<=9){
			for(int j=1;j<=js[i];j++){
				int p,a;
				cin>>p>>a;
				dp[p][m+i]=dp[m+i][p]=a;
			}
		}
		else if(c<=11){
			for(int j=0;j<js[i];j++)cin>>p[j][0]>>a[j][0];
			if(js[i]==2)dp[p[0][0]][p[1][0]]=min(dp[p[0][0]][p[1][0]],a[0][0]+a[1][0]);
		}
		else if(c==20 or c==21){
			for(int j=1;j<=js[i];j++){
				cin>>p[i][j];
				f[p[i][j]]+=i;
				cin>>a[i][p[i][j]];
			}
		}
	}
	if(c<=9)l=m+n;
	else if(c<=11)l=m;
	if(c<=11){
		for(int i=1;i<=l;i++)dp[i][i]=0;
		for(int k=1;k<=l;k++){
			for(int i=1;i<=l;i++){
				if(i==k)continue;
				for(int j=1;j<=l;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	else if(c==20 or c==21){
		zx=1e18;
		for(int i=1;i<=m;i++){
			if(!a[1][i] or !a[2][i])continue;
			else if(zx<a[1][i]+a[2][i])zx=a[1][i]+a[2][i],jss=1,pp[jss]=i;
			else if(zx==a[1][i]+a[2][i])pp[++jss]=i;
		}
		for(int i=1;i<=jss;i++)ff[pp[i]]=1;
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		if(c<=11){
			if(s>t)swap(s,t);
			cout<<x[s]+x[t]+dp[s][t]<<"\n";
		}
		else if(c==20 or c==21){
			if(f[s]==f[t] or f[s]==3 or f[t]==3){
				if(f[s]==3 and f[t]==3)cout<<x[s]+x[t]+min(a[1][s]+a[1][t],a[2][s]+a[2][t])<<"\n";
				else cout<<x[s]+x[t]+a[min(f[s],f[t])][s]+a[min(f[s],f[t])][t]<<"\n";
			}
			else{
				if(ff[s] or ff[t])cout<<x[s]+x[t]+zx+min(a[f[s]][s],a[f[t]][t])<<"\n";
				else cout<<x[s]+x[t]+zx+a[f[s]][s]+a[f[t]][t]<<"\n";
			}
		}
	}
	return 0;
}
