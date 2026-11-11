//王子畅 西安市含光中学 SN-J00809 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050],b[500050],ans[300050],sum[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		int x[300050];
		if(x[a[i]]==0){
			x[a[i]]=i;
			sum[i]=x[a[i]];
		}else{
			sum[i]=x[a[i]];
		}
	}
	for(int i=1;i<=n;i++){
		int y[300050]={};
		for(int j=i;j<=n;j++){
			if(sum[j]!=j){
				j=sum[j]-1;
			}else{
				if(y[a[j]]==0){
					y[a[j]]++;
					ans[a[j]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
