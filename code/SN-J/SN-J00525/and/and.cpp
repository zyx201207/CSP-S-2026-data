#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,g;
ll aa[200005];
ll dp[200005][10];
int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(ll i=1;i<=a;i++){
		cin>>aa[i];
	}
	for(ll i=1;i<=a;i++){
//		cout<<i<<"------------------------------------\n";
		for(ll j=1;j<=min(b,(long long)i);j++){
			if(j<=1){
				dp[i%2][j]=max(dp[(i+1)%2][j],aa[i]);
				
				//cout<<dp[i%2][j]<<" ";
				continue;
			}
			dp[i%2][j]=max(dp[(i+1)%2][j],dp[(i+1)%2][j-1]&aa[i]);4
//			cout<<dp[i%2][j]<<"("<<i<<" "<<j<<")-"<<(dp[(i+1)%2][j-1]&aa[i])<<"-"<<dp[(i+1)%2][j]<<" ";
		}
		//cout<<endl;
		if(i<b){
			for(int j=1;j<=b;j++){
				dp[i%2][j]=max(dp[i%2][j],aa[i]);
			}
		}
		
		//cout<<endl;
	}
	cout<<dp[a%2][b];
	fclose(stdin);
	fclose(stdout);
	return 0;
}



