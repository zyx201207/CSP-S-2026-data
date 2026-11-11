#include<iostream>
using namespace std;
long long dp[200005];
long long num[200005];
long long n,m;
long long maxn=-1;
void find(long long depth,long long s,long long value){
	if(depth>m){
		maxn=max(maxn,value);
		return ;
	}
	if(n-s<m-depth){
		return ;
	}
	for(int i=s+1;i<=n-m+depth;i++){
		find(depth+1,i,value&num[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n<=2000&&m!=n){
		for(int i=1;i<=n-m;i++){
			find(2,i,num[i]);
		}
		cout<<maxn;
		return 0;
	}else{
		dp[1]=num[1];
		for(long long i=2;i<=n;i++){
			for(long long s=m;s>=1;s--){
				if(s==1){
					dp[s]=max(dp[s],num[i]);
				}
				dp[s]=max(dp[s],dp[s-1]&num[i]);
			}
		}
		cout<<dp[m];
	}
	return 0;
} 
