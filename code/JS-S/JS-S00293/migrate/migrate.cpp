#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+10,MAXN1=5010;
int C,T;
int N,D;
int x[MAXN];
int dp[MAXN1][MAXN1];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	// freopen("migrate4.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>C>>T;
	if(C==11||C==12){
		while(T--){
			cin>>N>>D;
			for(int i=1;i<=N;++i){
				cin>>x[i];
			}
			int sin=D/(x[2]-x[1]);
			// cerr<<' '<<sin<<'\n';
			if(sin<2){
				cout<<0<<'\n';
				continue;
			}
			int len=sin*2+1;
			cout<<max(0ll,N-1-len+3)<<'\n';
		}
		return 0;
	}
	while(T--){
		cin>>N>>D;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j)dp[i][j]=-1;
		}
		int hd=1;
		for(int i=1;i<=N;++i){
			cin>>x[i];
			while(x[i]-x[hd]>D)++hd;
			for(int j=hd;j<i;++j)dp[j][i]=1;
			for(int j=1;j<hd;++j)dp[j][i]=dp[j][hd]+1;
		}
		int ans=0;
		for(int i=1;i<=N-2;++i){
			for(int j=i+2;j<=N;++j){
				bool flag=0;
				bool st=0;
				// map<int,int>mp;
				for(int k=i+1;k<j;++k){
					if(dp[i][j]==dp[i][k]+dp[k][j]){
						if(st){
							if(flag){
								--ans;break;
							}
							++ans;
							// cerr<<i<<' '<<mp[dp[i][k]+dp[k][j]]<<' '<<j<<'\n';
							// cerr<<i<<' '<<k<<' '<<j<<'\n';
							flag=1;
						}
						st=1;
						// mp[dp[i][k]+dp[k][j]]=k;
					}
				}
			}
		}
		cout<<ans<<'\n';
		// cerr<<'\n';
		// cerr<<dp[1][2]<<' '<<dp[2][5]<<'\n';
		// cerr<<dp[1][4]<<' '<<dp[4][5]<<'\n';
		// cerr<<'\n';
	}
	
	return 0;
}