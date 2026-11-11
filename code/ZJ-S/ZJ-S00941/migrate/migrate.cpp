//AC T3 at 17:51 
//wo yiwei CSP-S jieshu zai 18:00
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],fcg[2000010],fcgb[2000010];//fathest can go(back)
long long dp1[2000010],dp2[2000010],sum[2000010],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=2){
			cout<<"0\n";continue;
		}
		fcg[0]=ans=0;
		for(long long i=1;i<=n;i++){
			fcg[i]=fcg[i-1];
			while(fcg[i]!=n&&a[fcg[i]+1]-a[i]<=d)fcg[i]++;
			//cout<<fcg[i]<<' ';
		}
		//cout<<'\n';
		fcgb[n+1]=n+1;
		for(long long i=n;i>=1;i--){
			fcgb[i]=fcgb[i+1];
			while(fcgb[i]!=1&&a[i]-a[fcgb[i]-1]<=d)fcgb[i]--;
		}
		for(long long i=0;i<=n+1;i++)dp1[i]=dp2[i]=0;
		for(long long i=1;i<=n;i++){
			dp1[i]++;
			if(fcg[i]==fcg[i-1])dp1[i]=1;
			if(fcg[i]!=i&&fcg[i-1]!=fcg[i])dp1[fcg[i]]+=dp1[i];
			else if(fcg[i]!=i)dp1[fcg[i]]++;
			//cout<<dp1[i]<<' ';
		}
		//cout<<'\n';
		for(long long i=n;i>=1;i--){
			dp2[i]++;
			if(fcgb[i]==fcgb[i+1])dp2[i]=1;
			if(fcgb[i]!=i&&fcgb[i+1]!=fcgb[i])dp2[fcgb[i]]+=dp2[i];
			else if(fcgb[i]!=i)dp2[fcgb[i]]++;
			//cout<<dp2[i]<<' ';
		}
		//cout<<'\n';
		for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+dp2[i];
		for(long long i=2;i<=n-2;i++){
			int b=i,c=i+1;
			int afrom=fcgb[i+1],ato=fcgb[i+2]-1,dfrom=fcg[i-1]+1,dto=fcg[i];
			//cout<<afrom<<' '<<ato<<' '<<b<<' '<<c<<' '<<dfrom<<' '<<dto<<'\n';
			ato=min(ato,b-1);
			dfrom=max(dfrom,c+1);
			if(afrom>ato||dfrom>dto)continue;
			if(afrom>=2&&fcg[afrom-1]==i){
				if(dto<=n-1&&fcgb[dto+1]==i+1)ans+=(ato-afrom+1)*(dto-dfrom+1);
				else ans+=(ato-afrom+1)*(dto-dfrom+dp2[dto]);
			}else{
				if(dto<=n-1&&fcgb[dto+1]==i+1)ans+=(ato-afrom+dp1[afrom])*(dto-dfrom+1);
				else ans+=(ato-afrom+dp1[afrom])*(dto-dfrom+dp2[dto]);
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 1
10 2
1 2 3 4 5 6 7 8 9 10
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
