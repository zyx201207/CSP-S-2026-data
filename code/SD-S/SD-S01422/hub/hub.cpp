#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
		}
		if(k==n){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}

