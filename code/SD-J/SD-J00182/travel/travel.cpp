#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a1[10], a2[30], b1[30], b2[130];
	scanf("%s", a1 + 1);
	scanf("%s", a2 + 1);
	scanf("%s", b1 + 1);
	scanf("%s", b2 + 1);
	char ans[10];
	for(int i = 1; i <= 2; i++){
		if(a1[i] != b1[i]){
			printf("0000");
			return 0;
		}
	}
	for(int i = 1; i <= 2; i++){
		if(a2[i] != b2[i]){
			printf("1000");
			return 0;
		}
	}
	if((a2[3] <= 'C' && b2[3] > 'C') || (b2[3] <= 'C' && a2[3] > 'C')){
		printf("1100");
		return 0;
	}
	if((a2[3] + 1 != b2[3]) && (a2[3] - 1 != b2[3])){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
}
