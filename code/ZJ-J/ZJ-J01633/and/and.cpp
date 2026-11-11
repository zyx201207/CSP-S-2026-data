#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[200005];
int dp[200005];
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<max(n,m);i++){
		dp[i]=-1;
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int t,t1,t2;
	for(int i=0;i<n;i++){
		for(int v=m;v>=1;v--){
			if(dp[v-1]==-1){
				t=c[i];
			}else{
				t1=dp[v-1];
				t2=c[i];
				t=t1&t2;
			}
			if(dp[v]<t){
				dp[v]=t;
				a[v]+=1;
			}else{
				if(n-i-1+a[v]<m){
					dp[v]=t;
					a[v]+=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
