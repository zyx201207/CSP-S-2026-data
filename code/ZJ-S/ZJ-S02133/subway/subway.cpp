#include<bits/stdc++.h>
#define N 500005
typedef long long ll;
using namespace std;

int c,n,m,d,q;
int w[N];
int l[505][N];
int jx[505][505];
int a[505],flag = 0;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c >= 7 && c <= 11) flag = 1;
	if(c >= 12 && c <= 19) flag = 2;
	for(int i = 1 ; i <= m ; i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1 ; i <= n ; i++){
		int k;
		scanf("%d",&k);
		for(int j = 1 ; j <= k ; j++){
			int x,y;
			scanf("%d%d",&x,&y);
			l[i][x] = y;
		}
		for(int j = 1 ; j <= n ; j++)
	}
	
	return 0;
}
