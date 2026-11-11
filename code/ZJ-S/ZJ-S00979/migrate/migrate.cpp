#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,T,c,num[maxn][maxn];
long long a[maxn],f[maxn][maxn],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(f,63,sizeof f);
		memset(num,0,sizeof num);
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]<=d) f[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j],num[i][j]=1;
					else if(f[i][j]==f[i][k]+f[k][j]) num[i][j]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){//cout<<num[i][j]<<" ";
				if(num[i][j]==2) ans++;
			}//cout<<"\n";
		}
		printf("%d\n",ans);
	}
	return 0;
}
