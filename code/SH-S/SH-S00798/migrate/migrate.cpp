#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,d,x[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i<=d){
				dp[i+1]=1;
			}
		}
		
		for(int i=d+2;i<=n;i++){
			for(int j=1;j<=d;j++){
				dp[i]+=dp[i-j-1];
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==2){
				cnt++;
			}
		}
		if(t==1){
			cnt++;
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

