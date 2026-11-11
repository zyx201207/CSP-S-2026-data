#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	if(n>500 && m>200){
		for(int i=1;i<=m;i++){
			c[i]=c[i]+c[i-1];
			printf("%d ",c[i]);
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int f[500005],sum=0;
			memset(f,0,sizeof(f));
			for(int k=j;k<=n;k++){
				bool flag=0;
				int id=0;
				for(int t=1;t<k;t++){
					if(f[t]==a[k]){
						flag=1;
						id=t;
						break;
					}
				}
				if(!flag) f[++sum]=a[k];
				else{
					for(int t=id;t<k;t++) f[t]=0;
					sum=id;
					f[sum]=a[k];
				}
			}
			for(int k=1;k<=sum;k++){
				if(f[k]==i){
					ans++;
					break;
				}
			}
		}
		printf("%d ",ans);
	}
	return 0;
}
