#include <iostream>
using namespace std;
int C,t,n,k,s,u[100001],v[100001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
	}
	return 0;
}
