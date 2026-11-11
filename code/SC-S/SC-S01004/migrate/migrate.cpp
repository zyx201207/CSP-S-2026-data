#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	int c,t;
	scanf("%d%d",&c,&t);
	while(t){
		int n,d;
		scanf("%d%d",&n,&d);
		printf("%lld\n",rand()%n);
	}
	return 0;
}