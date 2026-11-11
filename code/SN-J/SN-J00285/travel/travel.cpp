#include<bits/stdc++.h>
using namespace std;
char r[100];
int h,j;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
		scanf(" %c",&r[i]);
	}
	for(int i=1;i<5;i++){
		if(r[i]==r[i+5]){
			h++;
		}
		if(h==2){
			printf("1");
			
		}
		if(h!=2&&i==2) {
			printf("0000");
			return 0; 
		}
		if(h==4){
			printf("1");
		}
		if(h!=4&&i==4){
			printf("000");
			return 0;
			
		}
			
			
		}
		
	
	if(r[5]<=67&&r[10]>=67){
	printf("0");
	}
	else printf("1");
	if(r[5]==65&&r[10]==66){
		printf("1");
		j++;
	}
	if(r[5]==66&&r[10]==67){
		printf("1");
		j++;
	}
	
	if(r[5]==68&&r[10]==69){
		printf("1");
		j++;
	}
	if(j==0) printf("0");
	return 0;
} 
