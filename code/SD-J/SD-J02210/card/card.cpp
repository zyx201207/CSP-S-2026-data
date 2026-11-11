#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],z[500005],cnt; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	if(m==2&&n>5000){
		int ans1,ans2;
		if(a[n]==2){
			ans2=n;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans1++;
			}
		}else if(a[n]==1){
			ans1=n;
			for(int i=1;i<=n;i++){
				if(a[i]==2) ans2++;
			}
		} 
		printf("%d %d",ans1,ans2);
	}
	for(int i=1;i<=n;i++){
		memset(z,0,sizeof(z));
		for(int j=i;j<=n;j++){
			z[++cnt]=a[j];
			for(int k=1;k<=cnt;k++){
				if(z[k]==a[j]){
					for(int y=k+1;y<=cnt;y++) z[y]=0;
					cnt=k+1;
				}
			}
		}
		for(int j=1;j<=cnt;j++) ans[z[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
