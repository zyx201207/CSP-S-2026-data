#include<bits/stdc++.h>
using namespace std;
struct num{
	int max;
	char d[100050];
}f[100050][100050];
int n,m,a[100050],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!f[k-1][j].d[i]){
					if(f[k][i].max < f[k-1][j].max&a[i]){
						f[k][i].max=f[k-1][j].max&a[i];
						for(int t=1;t<=n;t++){
							f[k][i].d[t]=f[k-1][j].d[t];
						}
						f[k][i].d[i]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[m][i].max);
	}
	printf("%d",ans);
	return 0;
}
