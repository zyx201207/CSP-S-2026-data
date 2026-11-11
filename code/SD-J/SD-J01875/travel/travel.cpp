#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]){
		if(a[1]==c[1]) printf("1");
		else{
			printf("0000");
			return 0;
		}
	}else{
		printf("0000");
		return 0;
	}
	if(b[0]==d[0]){
		if(b[1]==d[1]) printf("1");
		else{
			printf("000");
			return 0;
		}
	}else{
		printf("000");
		return 0;
	}
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='D'&&d[2]=='F')){
		printf("11");
		return 0;
	}else{
		if((b[2]<'D'&&d[2]>='D')||(b[2]>='D'&&d[2]<'D')){
			printf("00");
			return 0;
		}else{
			if(abs(b[2]-d[2]==1)){
				printf("11");
				return 0;
			}else{
				printf("10");
				return 0;
			}
		}
	}
	return 0;
}
