#include <bits/stdc++.h>
using namespace std;
char c[5][5];
int a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>c[1]>>a[2]>>c[2];
	if(a[1] == a[2]){
		printf("1");
		if(c[1][0] == c[2][0] && c[1][1] == c[2][1]){
			printf("1");
			if((c[1][2] <= 'C' && c[2][2] <= 'C') || (c[1][2] >= 'D' && c[2][2] >= 'D')){
				printf("1");
				if(abs(c[1][2] - c[2][2]) == 1){
					printf("1\n");
				}else{
					printf("0\n");
				}
			}else{
				printf("00\n");
			}
		}else{
			printf("000\n");
		}
	}else{
		printf("0000\n");
	}
	return 0;
}
