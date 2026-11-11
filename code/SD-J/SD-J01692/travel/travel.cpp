#include <iostream>
#include <stdio.h> 
using namespace std;
int a,b,c,d;
int a1,a2,a3,a4;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a,&b,&c1,&c,&d,&c2);
	if(a == c){
		a1 = 1;
		if(b == d){
			a2 = 1;
			if(c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C'){
				a3 = 1;
				if(c1 > c2){
					swap(c1,c2);
				}
				if(c2 - 1 == c1){
					a4 = 1;
				}
			}
			if((c1 == 'D'|| c1 == 'F') && (c2 == 'D' || c2 == 'F')){
				a3 = 1,a4 = 1;
			}
		}
	}
	printf("%d%d%d%d\n",a1,a2,a3,a4); 
	return 0;
} 
