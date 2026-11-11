#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,x[N],dp[5005][5005];
void solve(int u,int v){
	for(int i=u;i<=v;i++){
		for(int j=0;j<=u-v;j++){
			dp[i][j]=0;
		}
	}
	dp[u][0]=1;
	for(int i=u+1;i<=v;i++){
		for(int j=1;j<=i;j++){
			for(int k=u;k<i;k++){
				if(x[i]-x[k]<=d){
					dp[i][j]+=dp[k][j-1];
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int s=0,pan=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2)s=x[2]-x[1];
			if(i>2){
				if(x[i]-x[i-1]!=s)pan=0;
			}
		}
		if(pan){//等差数列
			int as=0;
			d=d/s*s;
//			for(int i=1;i<d/s;i++){
			    if(d/s-1>0){
					int len=d+(d/s-1)*s;
					if(x[n]-len>=x[1]){
						as+=(x[n]-len-x[1])/s+1;
					}
				}
//			}
			cout<<as<<endl;
		}
	}
	return 0;
}
//西风残照，汉家陵阙
//0 1
//5 2
//1 2 3 4 5

//0 1
//4 2
//1 2 3 4
