#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t; 
int n,d;
int x[2000020];
int dp[5050][5050];
int a[2000020]; 
int sum[5050]; 
void solve(){
	cin>>n>>d;
	bool flag=false;
	for(int i=1;i<=n;i++) cin>>x[i],a[i-1]=x[i]-x[i-1],flag=(a[i-1]==1)?true:flag;
	if(flag){
		d/=a[1]
		if(d<=1) cout<<"0\n";
		else{
			cout<<max(0,n-2*d+1)<<'\n';
		}
		return;
	}
} 
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
    return 0;
}
/*

快速打一下吧，这题40分部分分思路还是很好想的 
8分的特殊性质分也不难  
目前8分 

思路：
寻找每一段，并记录 
算了，不想思考了
脑子转不动，就不转了 
*/
