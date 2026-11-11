#include<bits/stdc++.h>
using namespace std;
int a[1005],f[105][105],ans,p[105][105];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		memset(f,63,sizeof f);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int p=a[2]-a[1];
		if(p>d){
			printf("0\n");
			continue;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j && j!=k && i!=k && f[i][j]>=f[i][k]+f[k][j]){
						if(f[i][j]==f[i][k]+f[k][j])
						    ans++;
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
