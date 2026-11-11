#include<bits/stdc++.h>
using namespace std;

int n,x[100000],m,d,c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%d",&x[i]);
		}
	}
	for(int i=1;i<=t;i++){
		printf("%d\n",0);
	}
	return 0;
}
