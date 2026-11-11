#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ans[M];
int n,m,l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int b[M]={};
		bool d[N]={};
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			d[j]=1;
			if(b[a[j]]){
				for(int k=b[a[j]];k<j;k++){
					ans[a[k]]-=d[k];
					d[k]=false;
					b[a[k]]=0;
				}
			}
			b[a[j]]=j;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
