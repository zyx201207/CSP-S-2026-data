#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m;
int dp[2005][2005];
int dfs(int x,int cnt,int ands){
	if(cnt==m){
		dp[x][cnt]=max(dp[x][cnt],ands);
		return ands;
	}
	if(x>=n){
		return 0;
	}
	int ret=0;
	for(int i=x+1;i<=n;i++){
		ret=max(ret,dfs(i,cnt+1,ands&a[i]));
	}
	dp[x][cnt]=ret;
	return ret;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
			return 0;
		}else if(m==n){
			int maxx=a[1];
			for(int i=2;i<=n;i++){
				maxx&=a[i];
			}
			cout<<maxx;
			return 0;
		}else if(m==2){
			int maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						maxx=max(maxx,a[i]&a[j]);
					}
				}
			}
			cout<<maxx;
			return 0;
		}else{
			sort(a+1,a+1+n,[](int a,int b){return a>b;});
			cout<<a[m];
			return 0;
		}
	}
	int mask=0;
	for(int i=0;i<=30;i++) mask|=1<<i;
	cout<<dfs(0,0,mask);
	return 0;
} 
