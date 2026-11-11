#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1, a2, b1, b2;
	int p1 = 0, p2 = 0;
	char c1, c2;
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(c1 <= 'C') p1 = 1;
	if(c2 <= 'C') p2 = 1;
	if(a1 == a2){
		printf("%d",1);
	}else{
		printf("%d%d%d%d",0,0,0,0);
		return 0;
	}
	if(b1 == b2){
		printf("%d",1);
	}else{
		printf("%d%d%d",0,0,0);
		return 0;
	}
	if(p1 == p2){
		printf("%d",1);
	}else{
		printf("%d",0,0);
		return 0;
	}
	if(max(c1,c2) - min(c1,c2) == 1){
		printf("%d",1);
	}else{
		printf("%d",0);
	}
	return 0;
}
