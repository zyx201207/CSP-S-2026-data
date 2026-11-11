#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N=2000005;

ll n,V,a[N],dp[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>V;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	for(int i=1;i<=V;++i) dp[i]=-0x3f3f3f3f;
	dp[0]=(1<<31)-1;
	
	for(int i=1;i<=n;++i){
		for(int j=V;j>=1;--j){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
		for(int j=0;j<=V;++j) cout<<dp[j]<<" ";
		cout<<endl;
	}
	
	
			
	cout<<dp[V];
	
	return 0;
}
