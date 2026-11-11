#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const long long MAX=1e18;
long long x[N];
int suf[N],s[505][505],dp[505][505];
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while (T--){
		int n;
		long long d;
		cin>>n>>d;
		if (n==1){
			cout<<0<<'\n';
			continue;
		}
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		if (C==11 || C==12){
			long long maxk=d/(x[2]-x[1]);
			if (maxk<=1){
				cout<<0<<'\n';
			}else{
				cout<<max(0ll,n-maxk*2+1)<<'\n';
			}
		}else{
			for (int i=1;i<=n;i++){
				if (x[n]-x[i]<=d){
					suf[i]=n;
				}else if (x[i+1]-x[i]>d){
					suf[i]=i;
				}else{
					suf[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;	
				}
			}
			if (C==13 || C==14){
				cout<<"Anteantibe is SB"<<'\n';
			}else{
				memset(s,0,sizeof(s));
				memset(dp,0,sizeof(dp));
				for (int i=1;i<=n;i++){
					//cout<<suf[i]<<'\n';
					for (int j=i+1;j<=n;j++){
						int tmp=i;
						while (tmp<j){
							s[i][j]++;
							if (tmp==suf[tmp]){
								s[i][j]=-1;
								break;
							}
							tmp=suf[tmp];
						}
					}
					//cout<<T<<'\n';
				}
				//cout<<"!!!"<<'\n';
				for (int i=1;i<=n;i++){
					for (int j=i+1;j<=n;j++){
						if (s[i][j]==1){
							dp[i][j]=1;
						}
						for (int k=j-1;suf[k]>=j && k>=i+1;k--){
							if (s[i][j]==s[i][k]+1){
								dp[i][j]++;
							}
						}
					}
				}
				int ans=0;
				for (int i=1;i<=n;i++){
					for (int j=i+1;j<=n;j++){
						//cout<<s[i][j]<<' '<<dp[i][j]<<'\n';
						if (dp[i][j]==2){
							ans++;
						}
					}
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
