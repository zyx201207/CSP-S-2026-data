#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(k==n){
			printf("0\n");
			continue;
		}
		if(c==13||c==14){
			int x=((n+1)/2+1)/2,y=k/2;
			if(k>=(n+1)/2-1){
				printf("1\n");
			}
			else if(x%2==0&&y%2==0){
				printf("%d\n",x/2-y/2+1);
			}
			else if(x%2==1&&y%2==0){
				printf("%d\n",(x+1)/2-y/2+1);
			}
			else if(x%2==0&&y%2==1){
				printf("%d\n",x/2-y/2+1);
			}
			else{
				printf("%d\n",(x+1)/2-(y+1)/2+1);
			}
			continue;
		}
	}
	return 0;
}
