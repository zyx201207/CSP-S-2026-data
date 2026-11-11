#include<bits/stdc++.h>
char a[2],b[3],c[2],d[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
	if(a[0]==c[0] && a[1]==c[1]){
		if(b[0]==d[0] && b[1]==d[1]){
			if((int(b[2]-'A')<=2 && int(d[2]-'A')<=2)||(int(b[2]-'A')>=3 && int(d[2]-'A')>=3)){
				if(abs(int(b[2]-'A')-int(d[2]-'A'))==1){
					std::cout<<"1111";
				}else{
					std::cout<<"1110";
				}
			}else{
				std::cout<<"1100";
			}
		}else{
			std::cout<<"1000";
		}
	}else{
		std::cout<<"0000";
	}
	
	
	return 0;
}