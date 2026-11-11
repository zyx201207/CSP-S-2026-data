#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,w[505];
ll f[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	if(m==2){
		for(int i=1;i<=n;i++)scanf("%d",w+i);
		
	}else{
		for(int i=1;i<=n;i++)scanf("%d",w+i);
		int k,a[505],t[505];
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++)f[i][i]=0;
		while(m--){
			scanf("%d",&k);
				for(int i=1;i<=k;i++){
					scanf("%d%d",a+i,t+i);
					for(int j=1;j<i;j++){
						f[a[i]][a[j]]=f[a[j]][a[i]]=min((ll)t[i]+t[j],f[a[i]][a[j]]);
					}
				}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int x,y;
		while(q--){
			scanf("%d%d",&x,&y);
			printf("%lld\n",f[x][y]+w[x]+w[y]);	
		}
	}
	return 0;
}
