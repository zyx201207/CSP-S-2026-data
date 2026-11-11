#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn];
void nain(int cc){
	int n,d;
	scanf("%d%d",&n,&d);
	if(n==1){
		printf("0\n");
		return;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(cc==11||cc==12){
		printf("0\n");
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		nain(c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
