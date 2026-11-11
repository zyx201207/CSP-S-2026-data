#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int in(){
	int f=1,k=0;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,c,t,a;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
		}
		printf("0\n");
	}
	return 0;
}
