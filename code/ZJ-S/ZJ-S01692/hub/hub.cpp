#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d%d",&T,&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(k==n) puts("0");
		else if(k>=n/2) printf("%d\n",1);
		else printf("%d\n",n/2-(k+1)/2+1);
	}
	return 0;
}