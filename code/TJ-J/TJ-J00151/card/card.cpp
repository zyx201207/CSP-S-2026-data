#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[300005];
long long cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(d[a[i]]==0){
			d[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		int id=d[a[i]]+1;
		while(id<=n){
			cnt[a[id]]++;
			id=d[a[id]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	printf("\n");
	return 0;
}
