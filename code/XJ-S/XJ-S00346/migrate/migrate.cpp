#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}
