#include<iostream>
#include<algorithm>
using namespace std;
long long n,d,a[2000005],dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1||n==2){
			cout<<0<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i]-a[j]<=d)
					dp[i][j]=1;
				else
					for(int k=1;k<=d;k++)
						dp[i][j]+=1;
				if(dp[i][j]==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
