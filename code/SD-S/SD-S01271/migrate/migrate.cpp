#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
int num[5010];
int f[310][310];
int minn[310];
int n,d;
void dfs(int x,int cnt){
	if(cnt>minn[x])return;
	f[x][cnt]++;
	minn[x]=min(minn[x],cnt);
	if(f[x][cnt]>3)return;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(i,cnt+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++){//从i开始的数对 
			for(int j=1;j<=n;j++)
			minn[j]=INT_MAX;
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(f[j][k]){
						if(f[j][k]==2){
							ans++;
//							printf("(%lld %lld %lld)",i,j,k);
						}
						break;
					}
				}
			}
			memset(f,0,sizeof(f));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
6 3
0 1 2 3 4 7
*/
