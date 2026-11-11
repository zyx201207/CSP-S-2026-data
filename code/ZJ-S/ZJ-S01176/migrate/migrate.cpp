#include <bits/stdc++.h>
using namespace std;

struct Node{
	int dis,cnt;
}; 

int c,t;
int n,d;
int x[2000005];
int dp[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migtare.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		//if(t==0)cout << "w";
		int n,d;
		int ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> x[i];

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//if(t==0)cout << 'w';
				dp[j]=0;
			}
			dp[i]=1;
			int r=i;
			while(r<=n){
				int r_=r+1;
				if(dp[r]==2)ans++;
				while(r_<=n && x[r_]-x[r]<=d){
					dp[r_]+=dp[r];
					r_++;
				}
				r++;
			}
		}
		cout << ans << endl;
	}
}