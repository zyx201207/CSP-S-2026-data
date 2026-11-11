#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e3;
int c,T;
int n;
long long d,ans;
long long a[MAXN+5],ct[MAXN+5][MAXN+5];

void solve(){
	ans=0;
	scanf("%d%lld",&n,&d);
	memset(ct,0,sizeof(ct));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d)break;
			ct[i][j]=(a[j]-a[i]-1)/d+1;//向上取整
		}
	}
//	printf("??\n");
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){ 
//			printf("%lld ",ct[i][j]);
//		}printf("\n");
//	}
	bool flag=0,wt=1;
	int las=0,z=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(ct[i][j]==0)break;
			flag=0;
			wt=1;
			las=0;
			for(int l=i+1;l<j;l++){
				if(ct[i][l]+ct[l][j]==ct[i][j]&&(ct[i][l]==z||z==-1)){
					las++;
					z=ct[i][l];
//					printf("%d %d %d %d %d\n",i,j,l,las,ans);
					if(las>=2){
						if(flag==0)flag=1;
						else{
							wt=0;
							break;
						}
					}
				}else{
					las=0;
				}
			}
			if(wt && flag==1){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/