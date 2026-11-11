#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[2000100],d,l,r,sum,c,p,vis[20000001],dp[5010][5010],minn[5010][5010],st;
vector<int> ed[2000001];
void wei(){
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3) {
			cout<<0<<'\n';
			continue;
		}
		for(int i=2;i<=n-2;i++){
			l=i-1;r=i+2;
			if(a[i+1]-a[i-1]<=d && a[i+2]-a[i]<=d && a[i+2]-a[i-1]>d){
				while(l>=2 && (a[l+1]-a[l-1]>d && a[l]-a[l-1]<=d)) l--;
				while(r<=n-1 && a[r+1]-a[r-1]>d && a[r+1]-a[r]<=d) r++;
				sum+=(i-l)*(r-i-1);
			}
		}
		cout<<sum<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c<=12 && c>=11) {
		wei();
		return 0;
	}
	while(t--){
		sum=0;
		cin>>n>>d;
		memset(ed,0,sizeof(ed));
		p=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d==1) {
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) {
			while(p<n && a[p+1]-a[i]<=d)
				p++;
			vis[i]=p;
			for(int j=i+1;j<=n;j++) minn[i][j]=-1,dp[i][j]=0; 
			dp[i][i]=1,minn[i][i]=0;
		}
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<'\n';
		for(int i=n-1;i>=1;i--){
			p=vis[i];st=1;
			for(int j=i+1;j<=n;j++){
				if(j>p) p=vis[p],st++;
				if(j>p) break;
				minn[i][j]=st;
			}
//			for(int j=i+1;j<=n;j++)cout<<minn[i][j]<<' ';cout<<'\n';
			for(int j=i+1;j<=n;j++){
				if(minn[i][j]==-1) break;
				if(j<=vis[i]) {
					dp[i][j]=1;
					continue;
				}
				for(int k=vis[i];k>i;k--){
					if(minn[k][j]+1==minn[i][j]) dp[i][j]+=dp[k][j];
					if(dp[i][j]>=3) break;
					if(dp[k][j]>=3) break;
					
				}
				if(dp[i][j]==2) sum++;
			}
/*			for(int j=i+1;j<=n;j++){
				if(minn[i][j]==-1) break;
				cout<<dp[i][j]<<' ';
			}cout<<'\n';*/
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
