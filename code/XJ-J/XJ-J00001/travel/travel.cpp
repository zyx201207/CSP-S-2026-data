#include<bits/stdc++.h>
using namespace std;

#define N 10
char a[N],b[N],c[N],d[N];
int h=0,j=0,k=0,l=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%c%c ",&a[0],&a[1]);
	scanf("%c%c%c ",&b[0],&b[1],&b[2]);
	scanf("%c%c ",&c[0],&c[1]);
	scanf("%c%c%c",&d[0],&d[1],&d[2]);
	
	if(a[0]==c[0] && a[1]==c[1]){
		h=1;
		if(b[0]==d[0] && b[1]==d[1]){
			j=1;
			if(b[2]<='C' && d[2]<='C'){
				k=1;
				if(b[2]-d[2]==1 || d[2]-b[2]==1){
					l=1;	
				}
			}
			if(b[2]>'C' && d[2]>'C'){
				k=1;
				if(b[2]-d[2]==1 || d[2]-b[2]==1){
					l=1;	
				}
			}
		}
	}
	printf("%d%d%d%d",h,j,k,l);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
