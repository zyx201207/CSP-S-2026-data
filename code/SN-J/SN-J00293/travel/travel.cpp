#include<bits/stdc++.h>
using namespace std;
struct travel{
	char che[3];
	char zuo[4];
}a[3]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	for(int i=1;i<=2;i++){
		scanf("%s",&a[i].che);
		scanf("%s",&a[i].zuo);
	}
	if(a[1].che[0]!=a[2].che[0]||a[1].che[1]!=a[2].che[1]){
		printf("0000");
		//printf("%c",a[1].che[2]);
		//printf("%c",a[2].che[1]); 
		return 0;
	}
	else{
		if(a[1].zuo[0]!=a[1].zuo[0]||a[2].zuo[1]!=a[1].zuo[1]){
			//printf("%c ",a[1].zuo[0]);
			//printf("%c",a[1].zuo[1]); 
			printf("1000");
			return 0;
		}
		else{
			if(a[1].zuo[2]=='A'||a[1].zuo[2]=='B'||a[1].zuo[2]=='C'){
				if(a[2].zuo[2]!='A'&&a[2].zuo[2]!='B'&&a[2].zuo[2]!='C'){
					//printf("%c ",a[1].zuo[2]);
					//printf("%c ",a[2].zuo[2]); 
					printf("1100");
					return 0;
				}
			}
			if(a[1].zuo[2]=='D'||a[1].zuo[2]=='E'){
				if(a[2].zuo[2]!='D'&&a[2].zuo[2]!='E'){
					printf("1100");
					return 0;
				}
			}
			else{
				if(a[1].zuo[2]-1!=a[2].zuo[2]&&a[1].zuo[2]+1!=a[2].zuo[2]){
					printf("1110");
					return 0;
				}
			}
		}	
	}
	printf("1111");
	return 0;
} 
