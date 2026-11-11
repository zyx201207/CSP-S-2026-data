#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,sa,b,sb;
	char pa,pb;
	scanf("%d %d%c %d %d%c",&a,&sa,&pa,&b,&sb,&pb);
	if(a!=b){
		printf("0000");
		return 0;
	}
	printf("1");
	if(sa!=sb){
		printf("000");
		return 0;
	}
	printf("1");
	if('A'<=pa && pa<='C' && 'A'<=pb && pb<='C'){
		printf("1");
		if(abs(pa-pb)==1){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else if((pa=='D' || pa=='F') && (pa=='D' || pa=='F')){
		printf("10");
	}
	else{
		printf("00");
		return 0;
	}

	return 0;
}