#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+9;
int c,T,n;
ll a[N],d,e[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)dp[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		int k=0;
		for(int i=1;i<=n;i++){
			e[i]=(lower_bound(a+1,a+1+n,a[i]+d)-a)-i;
			if(i<4)continue;
			for(int j=n-1;j>=1;j--){
				if(j+e[j]>n)dp[j]=dp[j+1]+1;
				else {
					if(dp[j+1]==dp[j+e[j]])k++;
					dp[j]=min(dp[j+1],dp[j+e[j]])+1;
				}
			}
		}
		cout<<k<<"\n";
	}
	return 0;
}
