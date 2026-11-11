#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
int ans[1010][1010],us[1010][1010],tong[1010][1010],a[1010],cnt[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		for(int j=1;j<=t;j++){
			int a;
			scanf("%d",&a);
			scanf("%d",&us[a][i]);
			tong[a][cnt[a]]=i;
			cnt[a]++;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){ans[i][j]=10086;
			for(int r=0;tong[i][r]!=0;r++){
				for(int l=0;tong[j][l]!=0;l++){
					if(tong[i][r]==tong[j][l]) ans[i][j]=min(ans[i][j],us[i][r]+us[j][l]);
				}
			}
		}
	}
	for(int i=1,r,l;i<=q;i++){
		scanf("%d%d",&r,&l);
		printf("%d",ans[r][l]+ans[l][r]+a[r]+a[l]);
	}
	return 0;
}
