#include<bits/stdc++.h>
using namespace std;
string tr1,tr2,se1,se2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>tr1>>se1>>tr2>>se2;
	if(tr1!=tr2){
		printf("0000");
		return 0;
	}
	printf("1");
	if(se1[0]!=se2[0] || se1[1]!=se2[1]){
		printf("000");
		return 0;
	}
	printf("1");
	if((se1[2]<='C')^(se2[2]<='C')){
		printf("00");
		return 0;
	}
	printf("1");
	if(abs(se1[2]-se2[2])==1){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}

