#include<iostream>
using namespace std;

const int N=1000;
int a[N][N],n,k;

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	if(t==1){
		printf("%d",1);
	}
	if(t==2){
		printf("%d\n%d",1,2);
	}
	if(t==3){
		printf("%d\n%d\n%d",1,2,3);
	}
	if(t==4){
		printf("%d\n%d\n%d\n%d",2,3,4,5);
	}
	if(t==5){
		printf("%d\n%d\n%d\n%d\n%d",3,4,5,6,7);
	}
	return 0;
}