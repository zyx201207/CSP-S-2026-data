#include <cstdio>
int n,m,a[200010],c[100010],s[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		s[i]=s[i-1]+c[i];
		printf("%d ",s[i]);
	}
	return 0;
}
