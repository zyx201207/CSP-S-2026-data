#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--){
		long long n,d,an=0;
		cin>>n>>d;
		vector<long long>x(n+2);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if((x[n]-x[1])>d){
			long long cn=0;
			for(int k=1;k+2<=n;k++){
				if((x[k+2]-x[k])<=d)cn++;
			}
			cn+=2;
			if(cn>=(d*2))cout<<cn-4+1;
		}
		/*for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				if((x[j]-x[i])>d){
					long long cn=0;
					for(int k=i;k+2<=j;k++){
						if((x[k+2]-x[k])<=d)cn++;
					}
					if(cn>=4)cout<<cn-4+1;
				}
				/long long dp[5003][5003];
				dp[i][i]=0;
				for(int k=i+1;k<=j;k++){
					for(int q=i+1;q<=j;q++){
						dp[k][q]=min(dp[])
					}
				}/
			}
		}*/
	}
	return 0;
}
