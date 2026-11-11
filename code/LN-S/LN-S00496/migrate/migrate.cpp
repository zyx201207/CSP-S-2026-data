#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	scanf("%d%d",&c,&t);
	int sum=0;
	while(t--){
		scanf("%d%d",&n,&d);
		int x[n+5];
		for(int i = 1;i<=n;++i){
			scanf("%d",&x[i]);
		}
		printf("%d",sum);
		++sum;
	}
	return 0;
}
