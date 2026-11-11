#include<cstdio>
#include<algorithm>
int a[200010];
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool first=true;
	long long ans=0;
	for (int k=30;k>=0;k--){
		int nowm=0;
		for (int i=1;i<=n;i++){
			if (first||vis[i]==true){
				if ((a[i]>>k)&1){
					nowm++;
				}
			}
		}
		if (nowm>=m){
			ans+=(1<<k);
			for (int i=1;i<=n;i++){
				if (first||vis[i]==true){
					if ((a[i]>>k)&1){
						vis[i]=true;
					}
			        else vis[i]=false;
				}
			}
			first=false;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
