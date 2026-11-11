#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000010];
//int pre[2000010],suf[2000010];
int rpos1[2000010],rpos2[2000010];
int dis[5010][5010];
int dp[5010][5010],predp[5010];
int pre[5010];
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			rpos1[i]=0x3f3f3f3f;rpos2[i]=0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			int last=i;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[last]<=d){
					dis[i][j]=dis[i][last]+1;
				}else{
					if(x[j]-x[j-1]>d){
						dis[i][j]=0x3f3f3f3f3f3f3f3f;continue;
					}
					dis[i][j]=dis[i][j-1]+1;
					last=j-1;
				}
				//cout<<i<<" "<<j<<"D"<<dis[i][j]<<'\n';
			}
		}
		rpos1[n+1]=0x3f3f3f3f;rpos2[n+1]=0x3f3f3f3f;
		int pos=1;
		for(int i=1;i<=n;i++){
			while(pos<=i){
				if(x[i]-x[pos]<=d){
					pre[i]=pos;break;
				}else{
					pos++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=(i==j);
			}
		}
		for(int i=1;i<=n;i++){

			for(int j=i;j<=n;j++){
				//cout<<max(i,pre[j])<<"B";
				for(int k=i;k<j;k++){
					if(x[j]-x[k]<=d&&dis[i][k]+dis[k][j]==dis[i][j]){
						dp[i][j]+=dp[i][k];
						//cout<<k<<"A";
					}
				}
				//cout<<j<<'\n';
				if(dp[i][j]==2)ans++;
			}
			predp[i]=dp[i][i];
			for(int j=i+1;j<=n;j++){
				predp[j]=predp[i]+dp[i][j];
			}
		}
		cout<<ans<<'\n';continue;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j-i<3){
					dp[i][j]=1;continue;
				}
				if(dis[j]-dis[i]<=d){
					dp[i][j]=1;continue;
				}
				int num=0;
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						num+=dp[i][k]*dp[k][j]-1;
						if(num>1){
							num=2;
							break;
						}
					}
				}
				dp[i][j]=num+1;
				if(num==1)ans++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
}
