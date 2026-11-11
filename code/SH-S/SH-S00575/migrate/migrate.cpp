#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,x[2000009],lm[2000009],rm[2000009];
namespace sol1{//O(n^3) 24pts?
	int cnt[2009][2009],sum[2009][2009],ans;
	void solve(){
		ans=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof cnt);
			memset(sum,0,sizeof sum);
			cnt[i][0]=1;
			sum[i][0]=1;
			for(int j=i+1;j<=n;j++){
				bool is_min=1;
				sum[j][0]=sum[j-1][0]+cnt[j][0];
				for(int k=1;k<=n;k++){
					cnt[j][k]=sum[j-1][k-1]-sum[lm[j]-1][k-1];
					sum[j][k]=sum[j-1][k]+cnt[j][k];
					//cout<<i<<".."<<j<<' '<<lm[j]<<' '<<k<<' '<<cnt[j][k]<<' '<<sum[j][k]<<'\n';
					if(cnt[j][k]==2&&is_min) ans++;
					if(cnt[j][k]) is_min=0;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
namespace solB{
	void solve(){
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int lp=n;
		for(int i=n;i>0;i--){
			while(x[i]-x[lp]<=d&&lp>0) lp--;
			lm[i]=lp+1;
		}
		int rp=1;
		x[n+1]=2e18;
		for(int i=1;i<=n;i++){
			while(x[rp]-x[i]<=d&&rp<=n) rp++;
			rm[i]=rp-1;
		}
		//for(int i=1;i<=n;i++) cout<<lm[i]<<" \n"[i==n];
		//for(int i=1;i<=n;i++) cout<<rm[i]<<" \n"[i==n];
		//if(C==13||C==14) solB::solve(); else
		sol1::solve();
	}
	return 0;
}
