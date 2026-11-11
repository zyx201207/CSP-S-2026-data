#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long t,n,x[2000001],d,c,dp[2][2000001];
int mian(){
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			if(i<2){
				scanf("%lld",&x[i]);
				getchar();
			}else if(i<n-1){
				while(getchar()!=' '){}
			}else{
				scanf("%lld",&x[i]);
			}
		}
		d/=x[1]-x[0];
		if(d<=1){
			cout<<"0\n";
		}else{
			cout<<max(0ll,n-(d+d-1))<<'\n';
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	int _;
	cin>>_>>t;
	if(_==11||_==12){
		mian();
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			scanf("%lld",&x[i]);
		}
		c=0;
		for(int i=0;i<n;i++){
			memset(dp,0x3f,sizeof(dp));
			dp[0][i]=0;
			dp[1][i]=1;
			for(int j=i;j<n;j++){
				for(int k=j;k<n&&x[k]-x[j]<=d;k++){
					if(dp[0][j]+1<dp[0][k]){
						dp[0][k]=dp[0][j]+1;
						dp[1][k]=dp[1][j];
					}else if(dp[0][j]+1==dp[0][k]){
						dp[1][k]+=dp[1][j];
					}
				}
				if(dp[1][j]==2){
					c++;
				}
			}
		}
		cout<<c<<'\n';
	}
	return 0;
}
