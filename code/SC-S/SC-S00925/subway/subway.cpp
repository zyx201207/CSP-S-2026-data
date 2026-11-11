#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q,s[500100],a[510][50100],x,y;
long long w[500100],t[510][50010],ans,tot=0x3f;
bool flagx,flagy,flagone;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
			tot=min(tot,t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%d%d",&x,&y);
		ans+=w[x]+w[y];
		flagone=0;
		for(int j=1;j<=n;j++){
			flagx=0;flagy=0;
			for(int k=1;k<=s[j];k++){
				if(a[j][k]==x){
					flagx=1;
				}
				if(a[j][k]==y){
					flagy=1;
				}
			}
			if(flagx==1&&flagy==1){
				flagone=1;
				break;
			}
		}
		if(flagone){
			printf("%lld\n",ans);
			continue;
		}
		ans+=tot;
		printf("%lld\n",ans);
	}
	return 0;
}
//公交换乘忘了怎么用BFS写了（只能骗分了TWT）