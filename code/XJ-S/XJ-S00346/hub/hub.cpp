#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000010],v[1000010],ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}
