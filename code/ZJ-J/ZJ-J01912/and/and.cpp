#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn=0;
int dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		printf("%d",maxn);
	}
	else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					maxn=max(maxn,a[i]&a[j]);
			}
		}
		printf("%d",maxn);
	}
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		printf("%d",maxn);
	}
	else if(m==3){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j&&j!=k&&i!=k)
						maxn=max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
		printf("%d",maxn);
	}
	else if(m==4){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i!=j&&j!=k&&i!=k&&i!=l&&j!=l&&k!=l)
						maxn=max(maxn,a[i]&a[j]&a[k]&a[l]);
					}
					
				}
			}
		}
		printf("%d",maxn);
	}
	else if(m==5){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int r=1;r<=n;r++){
							if(i!=j&&j!=k&&i!=k&&i!=l&&j!=l&&k!=l&&r!=l&&r!=k&&r!=j&&r!=i)
								maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[r]);
						}
						
					}
				}
			}
		}
		printf("%d",maxn);
	}
	else{
		dp[0]=0;
		dp[1]=maxn;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				dp[j]=max(dp[j-1],dp[j]&a[i]);
			}
		}
		int maxnn=0;
		for(int i=1;i<=m;i++){
			maxnn=max(maxnn,dp[i]);
		}
		printf("%d",maxnn);
	}
	return 0;
}
