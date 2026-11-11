#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],dp1[5010][5010],dp2[5010][5010],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(c<=10||c>=13){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dp1[i][j]=1e18,dp2[i][j]=0; 
			for(int len=2;len<=n;len++)
				for(int i=1;i+len-1<=n;i++){
					int j=i+len-1;
					if(x[j]-x[i]<=d){
						dp1[i][j]=1,dp2[i][j]=1;
						continue;
					}
					for(int k=i+1;k<=j-1;k++){
						if(dp1[i][k]+dp1[k][j]<dp1[i][j])
							dp1[i][j]=dp1[i][k]+dp1[k][j],dp2[i][j]=1;
						else if(dp1[i][k]+dp1[k][j]==dp1[i][j])
							dp2[i][j]+=dp2[i][k]*dp2[k][j];
					}
				}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					if(dp2[i][j]==2)
						ans++;
				}
			cout<<ans<<"\n";
		}
		if(c==11||c==12){
			if(d<x[3]-x[1]){
				cout<<0<<"\n";
				continue;
			}
			int f=1;
			for(int i=4;i*2-1<=n;i++){
				if(d<x[i]-x[1]){
					cout<<n-i*2+5<<"\n";
					f=0;
					break;
				}
			}
			if(f)
				cout<<0<<"\n";
		}
	}
	return 0;
}
