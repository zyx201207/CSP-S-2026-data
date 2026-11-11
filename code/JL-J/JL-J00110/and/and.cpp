#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
bool flag=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(flag!=i-1) flag=0;
	}
	sort(a+1,a+n+1);
	if(k==2){
		int ans=-1e9;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
	}
	else if(k==3){
		int ans=-1e9;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,(a[i]&a[j])&a[k]);
				}
			}
		}
		printf("%d",ans);
	}
	else if(flag){
		int ans1=a[1],ans2=a[n];
		for(int i=2;i<=k;i++){
			ans1&=a[i];
		}
		for(int i=n-1;i>=k;i--){
			ans2&=a[i];
		}
		printf("%d",max(ans1,ans2));
	}
	else printf("%d",a[n-k+1]);
	return 0;
}
