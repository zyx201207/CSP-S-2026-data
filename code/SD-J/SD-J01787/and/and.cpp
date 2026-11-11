#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+105;
int a[N],n,m,dp[35][N],vis[N];
void ddd(int x,int i){
	int cnt=0;
	while(x){
		dp[++cnt][i]=x%2;
		x/=2;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ddd(a[i],i);
	} 
	for(int i=33;i>=1;i--){
		int cnt=0;
		int x=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dp[i][j]==1){
				x++;
			}
		}
		if(x>=m){
			for(int j=1;j<=n;j++){
				if(dp[i][j]!=1) vis[j]=1;
			}	
		}
	}
	int x=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(x==-1) x=a[i];
			else x=x&a[i];
		}
	}
	cout<<x;
	return 0;
}
