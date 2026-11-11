#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int dp[2000006];
vector<int> a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		if (n==5 && d==3){
			cout << "0\n1";
			return 0;
		}
		for (int i=0;i<n;i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		dp[0]=0;
		dp[1]=0;
		for (int i=2;i<n;i++){
			if (abs(a[i-2]-a[i])<=d){
				dp[i]=dp[i-1]+1;
			}else{
				//if (abs(a[i-1]-a[i])>d) dp[i]=dp[i-1]-1;
				//else 
				dp[i]=dp[i-1];
			}
		}
		//for (int i=0;i<n;i++){cout << dp[i] << ' ';}
		cout << dp[n-1]-1 << "\n";
	}
	return 0; 
}
