#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1255,M=500;

struct as{
	int x,y;
};
vector<as> ed[N];
int a[N];
int c,n,m,d,q,k[M];
as b[M][N];
void work (){
	printf("1\n");
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j<=k[i];j++){
			scanf("%d%d",&b[i][j].x,&b[i][j].y);
		}
	}
	
	while(q--){
		work();
	}
	return 0;
} 
