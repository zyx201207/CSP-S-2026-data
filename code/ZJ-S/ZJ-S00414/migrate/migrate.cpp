#include<bits/stdc++.h>
using namespace std;
const int BIGN=2e6+10,N=5010;
int c,T,n;
long long a[BIGN],d,dp1[N][N],dp2[N][N];
void te(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ce=d/(a[2]-a[1]);
		if(ce<=1) cout<<"0\n";
		else cout<<max(n-3-(ce-2)*2,0LL)<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		te();
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp1[i][j]=1e18;
				dp2[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dp1[i][i]=0;
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					if(a[j]-a[k]<=d) dp1[i][j]=min(dp1[i][j],dp1[i][k]+1);
				}
			} 
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			dp2[i][i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					if(a[j]-a[k]<=d&&dp1[i][k]+1==dp1[i][j]) dp2[i][j]+=dp2[i][k];
				}
				if(dp2[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
