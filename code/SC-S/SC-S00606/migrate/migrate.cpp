#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;

int c,t;
int n;
long long d,a[N];
long long dp[N];

long long ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)dp[i]=1;
		for(int i=1,j=1;i<=n;i++){
			j=max(i,j);
			while(a[j+1]-a[i]<=d&&j+1<=n){
				j++;
				if(a[j+1]-a[i]>d){
					break;
				}
			}
			if(i!=j)
				dp[j]+=dp[i];
		}
		for(int i=1,j,h;i+2<n;i++){
			if(a[i+2]-a[i]>d)continue;
			if(a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d){
				ans+=dp[i];
				j=max(i+4,j);
				while(j<=n&&a[j]-a[i]<=d)j++;
				h=j;
				if(a[h]-a[i+1]>d)continue;
				while(h+1<=n&&a[h+1]-a[i+1]<=d)h++;
				if(a[j]-a[i]>d&&a[j]-a[i+1]<=d&&a[h-1]-a[i+1]<=d)ans+=(h-j+1)*dp[i];
				
				else continue;	
			}
			
//			cout<<"i j h="<<i<<" "<<j<<" "<<h<<endl;
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
//		cout<<endl;
//		cout<<"/////"<<endl<<endl;
	}
	return 0;
} 
/*
0 1
6 12
 -10 -6 -2 2 6 10
*/
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
*/ 
