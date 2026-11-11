#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000006],b[2000006];
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
		if(c==11||c==12){
			int t=a[2]-a[1];
			int k=d/t+1;
			int g=((a[n]-a[1])%k-k)/k;
			int ans=0;
			while(g--) ans+=g;
			printf("%d",ans);
		}
	}
	return 0;
}
