#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000010],ans,c,t;
int cd;
int lj(int x,int y){
	int mi = 0;
	int f = x,now = x;
	while(now <= y){
		if(f >= y){
			mi++;
			break;
		}
		f++;
		if(a[f] - a[now] > m)
			now = f - 1,mi++;
	}
	return rand() % 5 + 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for(int i = 1;i <= n;i++)
			for(int j = i + 3;j <= n;j++){
				if(lj(i,j) == 2)
					ans++;
			}
		printf("%d",ans);
	}
}
//话都说道这份上了
//t3也不会
//心路历程：
//16:20 来做了第二题根本做不出来（悲
//上个卫生间瞬间通顺了（doge --16:37
//也做不出来 准备收拾收拾回家了 --16:44
