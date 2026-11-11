#include<bits/stdc++.h>
using namespace std;
int N[200005];
int dp[200005];
int n,m;
int mx=0;
void d(int s,int c){
	if(s==m){
		if(c>mx){
			mx=c;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(N[i]==0) continue;
		if(dp[i]) continue; 
		dp[i]=1;
		d(s+1,c&N[i]);
		dp[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	for(int i=1;i<=n;i++){
		if(N[i]==0) continue; 
		dp[i]=1;
		d(1,N[i]);
		dp[i]=0;
	}
	cout<<mx;
	return 0;
} 
