#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int man=5e3+10;
ll dp[man][man],dis[man][man],wez[man],n,d,ans;
void solve(){
	memset(dp,0,sizeof dp);
	memset(dis,0x3f,sizeof dis);
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>wez[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int trd=i;
		for(int j=i-1;j;j--){
			if(wez[j+1]-wez[j]>d)continue;
			if(wez[trd]-wez[j]>d&&wez[trd]-wez[j+1]<=d){
				trd=j+1;
			}
			dis[i][j]=dis[j][i]=dis[i][trd]+1;
			if(trd==i)dp[j][i]=1;
			else{
				ll pos=lower_bound(wez+1,wez+n+1,wez[j]+d)-wez;
				for(int k=j+1;k<=pos;k++){
					dp[j][i]+=dp[k][i];
				}
				if(dp[j][i]==2)ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}