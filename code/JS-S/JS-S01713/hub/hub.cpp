#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(0);
	scanf("%d%d",&c,&t);
	while(t--){
		int a=rand()%100000;
		printf("%d",a);
	}
	return 0;
}
