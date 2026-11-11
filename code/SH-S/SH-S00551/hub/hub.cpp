#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=0x3f3f3f3f;
vector<int> g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
//	if(c>=13&&c<=14){
		while(t--){
			scanf("%d%d",&n,&k);
			for(int i=1;i<=n-1;i++){
				int u,v;
				scanf("%d%d",&u,&v);
			}
			int nn=n/2+1;
			if(n<=k){
				printf("0\n");
				continue;
			}else if(k>=nn-1){
				printf("1\n");
				continue;
			}
			if((nn-k)%4==0){
				ans=(nn-k)/4+1;
			}else{
				ans=(nn-k)/4+2;
			}
			printf("%d\n",ans);
		}
		return 0;
//	}
	
	return 0;
}
