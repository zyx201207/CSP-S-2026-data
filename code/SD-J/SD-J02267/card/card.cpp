#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m,k,a[N],b[N],cnt[M];
bool isA=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i!=1&&a[i-1]>a[i]){
			isA=0;
		}
	}
	if(isA){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			printf("%lld ",cnt[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		k=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			for(int w=1;w<=k;w++){
				if(a[j]==a[w]){
					k=w-1;
					for(int z=w;z<=k;z++){
						b[z]=0;
					}
				}
			}
			b[++k]=a[j];
		}
		for(int j=1;j<=k;j++){
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",&cnt[i]);
	}
	return 0;
}
