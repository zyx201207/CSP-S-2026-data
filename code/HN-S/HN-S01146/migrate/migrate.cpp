#include<bits/stdc++.h>
#define kks 2000010
#define inf 2147483647
using namespace std;
int c,t,n,d,a[kks],f[kks],s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int ob=0;
		s=0;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1&&a[i]-a[1]<=d) f[i]=1,ob=i;
		}
		for(int i=ob;i<=n;i++){
			f[i]=inf;
			for(int j=i-1;j>0&&a[i]-a[j]<=d;j--) f[i]=min(f[i],f[j]);
			f[i]++;
			if(f[i]==2) s++;
		}
		printf("%d\n",s);
	}
	return 0;
}
