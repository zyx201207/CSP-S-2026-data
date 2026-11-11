#include<bits/stdc++.h>
using namespace std;long long int n,nn,m,a[500001],c[300001],d[300001];

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;nn=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){	
		for(int j=i;j<=n;j++){
			if(c[a[j]]){
				for(int o=j-1;a[o]!=a[j];o--){
					d[a[o]]-=c[a[o]];
					c[a[o]]=0;
				}
			}else{
				c[a[j]]=1;
				d[a[j]]++;
			}
		}
		for(int j=0;j<=n;j++)c[a[j]]=0;
	}
	printf("%d",d[1]);
	for(int i=2;i<=m;i++){
		printf(" %d",d[i]);
	}
}