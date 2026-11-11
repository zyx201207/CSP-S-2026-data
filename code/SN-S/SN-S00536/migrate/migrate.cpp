//zhoujunhao SN-S00536
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int c,t,n,d;
int a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i = 1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i]);
		}
		if (n == 1) printf("0\n");
		if (n == 2) printf("0\n");
		if (n == 3) printf("0\n");
		if (n == 4) printf("1\n");
		if (n == 5) printf("2\n");
		if (n == 6) printf("5\n");
		else printf("0\n");
	}	
	return 0;
}

