#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int preW[300005];
int getN[300005];
int anss[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool TA=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		if(i>1&&a[i-1]>a[i]){
			TA=0;
		}
	}
	if(TA){
		for(int i=2;i<=n;i++){
			if(a[i-1]!=a[i]){
				printf("%d ",i-1);
			}
		}
		printf("%d",n);
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(getN,0,sizeof(getN));
			memset(preW,0,sizeof(preW));
			for(int j=i;j<=n;j++){
				if(getN[a[j]]==0){
					getN[a[j]]=1;
					preW[a[j]]=j;
				}
				else if(getN[a[j]]==1){
					for(int k=preW[a[j]];k<=j;k++){
						getN[a[k]]=0;
						preW[a[k]]=0;
					}
					getN[a[j]]=1;
					preW[a[j]]=j;
				}
			}
			for(int j=1;j<=m;j++){
				anss[j]=anss[j]+getN[j];
			}
		}
//		for(int i=n;i>=1;i--){
//			if(getN[a[i]]==0){
//				getN[a[i]]=1;
//				preW[a[i]]=i;
//			}
//			else if(getN[a[i]]==1){
//				for(int k=i;k<=preW[a[i]];k++){
//					getN[a[i]]=0;
//					preW[a[i]]=0;
//				}
//				getN[a[i]]=1;
//				preW[a[i]]=i;
//			}
//			for(int j=1;j<=m;j++){
//				anss[j]=anss[j]+getN[j];
//			}
//		}
		for(int i=1;i<=m;i++){
			printf("%d ",anss[i]);
		}
	}
	return 0;
}





//我要完蛋了，我这一生如履薄冰 
