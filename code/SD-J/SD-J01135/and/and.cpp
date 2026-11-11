#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],dp[N],f[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=N;i++){
    	dp[i]=f[i]=1;
	}
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);	
	dp[0]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if((dp[j-1]&a[i])==0){
				dp[j-1]=a[i];
			}
			dp[j]=max(dp[j],dp[i-j]&a[i]);
			
		}
	}
	f[0]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],(f[i-j]&a[i]));
		}
	}
	cout<<max(dp[m],f[m]);
	return 0;
}
