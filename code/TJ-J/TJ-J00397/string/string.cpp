#include<stdio.h>
long long m,n,p,r;
char o,q[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		scanf("%d%c",&n,&o);
		for(int j = p;p < n + j;p++) q[p] = o;
	}
	for(int i = 0;i < p / 2;i++) if(q[i] ^ q[p - i - 1]) r++;
	if(2 * r > p) printf("%d",r);
	else printf("%d",p - r);
	return 0;
}
