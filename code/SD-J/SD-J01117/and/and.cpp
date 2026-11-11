#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,dp[25][25];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		printf("%d",ans);
	}
	else if(n<=2000){
		if(m==1){
			ans=0;
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			printf("%d",ans);
		}
		else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			printf("%d",ans);
		}
		else{
			ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			printf("%d",ans);
		}
	}
	else{
		if(m==n-1){
			ans=0;
			for(int i=1;i<=n;i++){
				int sum=pow(2,21)-1;
				for(int j=1;j<=n;j++){
					if(a[i]!=a[j]){
						sum&=a[j];
					}
				}
				ans=max(ans,sum);
			}
		}
		else{
			sort(a+1,a+n+1,cmp);
			ans=a[1];
			for(int i=2;i<=m;i++){
				ans&=a[i];
			}
			printf("%d",ans);	
		}
	}
	return 0;
}
