#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100005];
int min_lj(int a,int b,int cj){
	if(cj=1 && x[b]-x[a]<=d) return 1;
	for(int i=cj;i>0;i--){
		if(x[a+i]-x[a]<=d) return 1+min_lj(a+i,b,cj-i);
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		int dp[n][n],ans=0;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
        ans=0;
		for(int i=0;i<n-3;i++){
			for(int j=i+3;j<n;j++){
				dp[i][j]=min_lj(i,j,j-i);
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
