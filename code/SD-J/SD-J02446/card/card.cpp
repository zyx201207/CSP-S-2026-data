#include<bits/stdc++.h>
using namespace std;
const int maxx=5e5+5;
const int maxn=3e5+5;
int n,m;
int a[maxx],hv[maxn];
int z[maxn];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f=f&&(a[i]>=a[i-1]);
		hv[a[i]]++;
	}	
	if(f){
		for(int i=1;i<=m;i++){
			if(hv[i]==1){
				printf("%d ",i);
			}
			else{
				int x=hv[i]/2;
				printf("%d ",x+(hv[i]%2!=0));
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(hv,0,sizeof(hv));
		int l=0,r=0;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(hv[x]){
				for(int k=hv[x];k<j;k++){
					hv[a[k]]=0;
				}	
			}
			hv[x]=j;
		}
		for(int i=1;i<=m;i++){
			if(hv[i]){
				z[i]++;
			}
		} 
	}
	for(int i=1;i<=m;i++){
		printf("%d ",z[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
