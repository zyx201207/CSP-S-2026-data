#include<cstdio>
#include<algorithm>
int m;
int n=0;
char a[100000012];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int c;
		char x;
		char t;
		scanf("%d %c",&c,&x);
		for(int i=1;i<=c;i++){
			a[++n]=x;
		}
	}
	//for(int i=1;i<=n;i++)printf("%c",a[i]);
	//puts("");
	int ans=0;
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1])ans++;
	}
	printf("%d\n",ans);
	return 0;
}
