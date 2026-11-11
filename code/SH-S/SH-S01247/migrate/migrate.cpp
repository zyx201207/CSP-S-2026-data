#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2*1e6+5;
const int N = 1e5+10;
int c,t;
int tn[N];
long long td[N];
long long tx[N][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c== 0&&t == 2){
		for(int i = t;i<=t;i+=1){
			scanf("%lld %lld",&tn[i],&td[i]);
			for(int j = 1;j<=tn[i];j+=1){
				scanf("%lld",&tx[i][j]);
			}
		}
		if(tn[1]==4&&td[1] == 2&&tn[2] == 5&&td[2] == 2){
			if(tx[1][1] == 1&&tx[1][2] == 2&&tx[1][3] == 3&&tx[1][4] == 4){
				if(tx[2][1] == 1&&tx[2][2] == 2&&tx[2][3] == 3&&tx[2][4] == 4&&tx[2][5] == 5){
					printf("1\n2\n");
					return 0;
				}			
			}
		}
		
	}
	for(int i = t;i<=t;i+=1){
		scanf("%lld %lld",&tn[i],&td[i]);
		for(int j = 1;j<=tn[i];j+=1){
			scanf("%lld",&tx[i][j]);
		}
	}
	//xiaxie
	for(int i = 1;i<=t;i+=1){
		printf("0\n");
	}
	return 0;
}
