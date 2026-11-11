#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[210][500010],	t[210][500010];
int k[210],w[500010];
int f1[210],f2[500010];
int main(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
	}
}
//你说会有人来看t2吗
//我不造啊
//心路历程：
//其实根本不会 t2··· --15:10
//啥也不会只能回来看这个了 --15:12
//阅读理解也看不懂已经准备回家了 --15:18
//dp? -- 15:33
//不是5e5是啥范围啊 --15:39
//已经开始暴力耍起了--15:41
//我承认我怕了我真的不想做这个题--15:53
//1 2 3 tiao --16:25
