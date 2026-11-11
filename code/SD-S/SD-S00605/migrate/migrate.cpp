#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans*=10;
		ans+=c-'0';
		c=getchar();
	}
	return ans*f;
}
const int MAXN=2e6+10;
const int MAXX=1e7;
int dp[305][305];
int dp2[305][305];
int dp3[305][305];
int a[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	C=read();
	T=read();
	while(T--){
		int n,d;
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(C>=1&&C<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp2[i][j]=0x3f3f3f3f;
					dp3[i][j]=0x3f3f3f3f;
					if(abs(a[i]-a[j])<=d){
						dp[i][j]=1;
					}
					else{
						dp[i][j]=0x3f3f3f3f;
					}
				}
				dp[i][i]=0;
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(i==j||j==k||i==k){
							continue;
						}
						if(dp[i][k]+dp[k][j]<=dp[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp[i][j];
							dp[i][j]=dp[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 1"<<endl;
						}
						else if(dp[i][k]+dp[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp[i][k]+dp[k][j]<=dp3[i][j]){
							dp3[i][j]=dp[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp[i][k]+dp2[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp[i][k]+dp2[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp[i][k]+dp2[k][j]<=dp3[i][j]){
							dp3[i][j]=dp[i][k]+dp2[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp2[i][k]+dp[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp2[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp2[i][k]+dp[k][j]<=dp3[i][j]){
							dp3[i][j]=dp2[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp2[i][k]+dp2[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp2[i][k]+dp2[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp2[i][k]+dp2[k][j]<=dp3[i][j]){
							dp3[i][j]=dp2[i][k]+dp2[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp[i][k]+dp3[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp[i][k]+dp3[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp[i][k]+dp3[k][j]<=dp3[i][j]){
							dp3[i][j]=dp[i][k]+dp3[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp3[i][k]+dp[k][j]<=dp2[i][j]){
							dp3[i][j]=dp2[i][j];
							dp2[i][j]=dp3[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 2"<<endl;
						}
						else if(dp3[i][k]+dp[k][j]<=dp3[i][j]){
							dp3[i][j]=dp3[i][k]+dp[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp3[i][k]+dp2[k][j]<=dp3[i][j]){
							dp3[i][j]=dp3[i][k]+dp2[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp2[i][k]+dp3[k][j]<=dp3[i][j]){
							dp3[i][j]=dp2[i][k]+dp3[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
						if(dp3[i][k]+dp3[k][j]<=dp3[i][j]){
							dp3[i][j]=dp3[i][k]+dp3[k][j];
							//cout<<k<<" "<<i<<" "<<j<<" 3"<<endl;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp2[i][j]<<" "<<dp3[i][j]<<endl;
					if(dp[i][j]<MAXX&&dp2[i][j]<MAXX&&dp[i][j]==dp2[i][j]&&dp2[i][j]!=dp3[i][j]){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(C==11||C==12){
			int b=abs(a[1]-a[2]);
			//cout<<b<<" "<<d/b<<endl;
			if(d/b<=1){
				cout<<"0\n";
			}
			else{
				int p=d/b;
				int pp=p+p-1;
				cout<<max(0ll,n-pp)<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
