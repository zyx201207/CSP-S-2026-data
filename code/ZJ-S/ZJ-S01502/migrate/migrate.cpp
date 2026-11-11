#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++){
		int n,d;
		scanf("%d %d",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
		int o=abs(a[2]-a[1]);
		if(d<=o) printf("0\n");
		else{
			int ans=0;
			for(int len=2;len<=n;len++){
				for(int j=1;j+len-1<=n;j++){
					int p=d/o;
					int y=(a[j+len-1]-a[j])/o;
					if(y%p==0||y<p) printf("");
					else ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
