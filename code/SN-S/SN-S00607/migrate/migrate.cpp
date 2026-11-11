#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000010],dp[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=i+d;k++){
					dp[k]=1;
				}
				
				long long minn=1000000000;
				for(int k=i+d+1;k<=j-1;k++){
					for(int x=k-d;x<=k-1;x++)
					{
						minn=min(minn,dp[x]+1);
					}
					dp[k]=minn;
				}
				if(dp[j]==1)continue;
				bool flag=0;
				cout<<j<<d;
				for(int ca=j-d;ca<=j-1;ca++){
					cout<<ca;
					for(int cb=j-d;cb<=j-1;cb++){
						cout<<cb;
						if(ca!=cb&&dp[ca]==dp[cb]){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
				if(flag)
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
		for(int i=1;i<=n;i++){
		    dp[i]=0;
		}
		for(int i=1;i<=n;i++){
		    a[i]=0;
		}
    }
	return 0;
}
