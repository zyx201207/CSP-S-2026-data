#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[250010],k[510],x[100010],y[10010];
map<pair<int,int>,int>a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[{i,j}],&t[{i,j}]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			printf("%d\n",w[x[i]]+w[y[i]]+t[{1,x[i]}]+t[{1,y[i]}]);
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

12 2 3 20 1
4 1 9
3 1 5 2 7 3 6
3 1 5 2 7 3 6
1 3
*/
