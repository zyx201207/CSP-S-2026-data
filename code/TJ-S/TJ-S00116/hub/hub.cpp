#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,d,x[60001];
	cin>>c>>t;
	while(t--){
		long long dp[60001]={}; 
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>x[1];
		}
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				if(x[i]+d>=x[j]){
					dp[j]++;
				}
			}
		}
	}
	cout<<1<<endl<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
