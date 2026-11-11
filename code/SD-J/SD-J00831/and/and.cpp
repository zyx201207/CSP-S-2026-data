#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m;
long long a[2*100000+10];
long long dp[25][2];
bool vis[25];
long long maxx=-1e18;
long long p=0;
void dfs(long long x,long long w,long long q){
	if(x==n&&w==m){
		maxx=max(maxx,q);
		return;
	}
	if(x==n){
		return;
	}
	for(long long i=x+1;i<=n;i++){
		if(w!=0) dfs(i,w,q);
		else dfs(i,w+1,a[i]);
		dfs(i,w+1,q&a[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0);
		dfs(1,1,a[1]);
		cout<<maxx;
		return 0;
	}
	else if(n<=2000){
		if(m==1){
			long long maxp=-1e18;
			for(int i=1;i<=n;i++){
				maxp=max(maxp,a[i]);
			}
			cout<<maxp;
		}
		else if(m==2){
			long long maxp=-1e18;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					else{
						maxp=max(maxp,a[i]&a[j]);
					}
				}
			}
			cout<<maxp;
		}
		else{
			long long x=a[n];
			for(int i=1;i<=n-1;i++){
				x&=a[i];
			}
			cout<<x;
		}
	}
	return 0;
}
