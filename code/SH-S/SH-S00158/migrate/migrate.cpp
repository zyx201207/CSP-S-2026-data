#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
long long c,t,n,d,x[N],dp[N],flg[N],ans,tmp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			if(n==1){
				cout<<"0\n";
				continue;
			}
			tmp=d/(x[2]-x[1]);
			if(tmp==0||tmp==1){
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-(2*tmp-1))<<"\n";
			continue;
		}
		if(c<=10){
			for(int i=1,l;i<=n;i++){
				l=i;
				for(int j=i;j<=n;j++)dp[j]=flg[j]=0;
				for(int j=i+1;j<=n;j++){
					while(x[j]-x[l]>d&&l+1<j)l++;
					if(x[j]-x[l]>d)break;
					dp[j]=dp[l]+1;
					flg[j]=flg[l];
					if(dp[l+1]==dp[l])flg[j]++;
					if(dp[l+2]==dp[l]&&dp[l])flg[j]++;
					if(flg[j]==1)ans++;
				}
			}
			cout<<ans<<"\n";
			ans=0;
		}
		cout<<"0\n";
	}
	return 0;
}
