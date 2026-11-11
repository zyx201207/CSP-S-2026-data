#include<bits/stdc++.h>
using namespace std;

const int mn=502,mm=2e4+2;
int c,n,m,d,q;
int w[mm],k[mn],a[mn][mm][2];
long long ans;
int u[mm][mm];
int e,f;
int x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		scanf("%d",&a[i][1][0]);
		scanf("%d",&a[i][1][1]);
		for(int j=2;j<=k[i];j++){
			scanf("%d",&a[i][j][0]);
			scanf("%d",&a[i][j][1]);
			u[a[i][j][0]][a[i][j-1][0]]=-1;
			u[a[i][j-1][0]][a[i][j][0]]=-1;
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				if(i==k){
					continue;
				}
				for(int j=i+1;j<=m;j++){
					if(j==k||(u[i][k]==0||u[k][j]==0)||u[i][j]==-1){
						continue;
					}
					int U=u[i][k]+u[k][j];
					if(u[i][k]==-1||u[k][j]==-1){
						if(u[i][j]==0){
							u[i][j]=U+1;
						}else{
							u[i][j]=min(U+1,u[i][j]);
						}
					}else{
						if(u[i][j]==0){
							u[i][j]=U;
						}else{
							u[i][j]=min(U,u[i][j]);
						}
					}
				}
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d",&x);
			scanf("%d",&y);
			ans=(w[x]+w[y]+u[min(x,y)][max(x,y)]);
			printf("%ll ",ans);
		}
	}
	return 0;
}