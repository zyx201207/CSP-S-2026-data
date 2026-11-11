#include<bits/stdc++.h>
using namespace std;
const int N=2000100;
long long c,t,n,d,x[N],dp[N][4];
void inst(long long j,long long k){
	long long a=1,b=1;
	long long kk[4];
	long long tot=1;
	while(tot<=3){
		if(dp[j][a]+1<dp[k][b]){
			kk[tot++]=dp[j][a]+1;
			a++;
		}else{
			kk[tot++]=dp[k][b];
			b++;
		}
	}
	for(int i=1;i<=3;i++){
		dp[k][i]=kk[i];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int u=1;u<=n;u++)
				memset(dp[u],sizeof(dp[u]),0x3f);
			dp[i][1]=1;
			for(int j=i;j<=n;j++){
				if(dp[j][1]==dp[j][2]&&dp[j][2]!=dp[j][3]&&dp[j][1]!=0x3f3f3f3f)cnt++;
				for(int k=j+1;k<=n;k++){
					if(x[k]-x[j]>d)break;
					inst(j,k);
				}
//				for(int y=1;i<=n;y++){
//					for(int u=1;u<=3;u++){
//						cout<<dp[y][u]<<' ';
//					}
//					cout<<'\n';
//				}
//				cout<<'\n';
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}