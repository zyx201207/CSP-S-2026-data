#include<bits/stdc++.h>
std::ifstream cin("travel1.in");
std::ofstream cout("travel1.out");
int main(){
	int c1,c2,num=0;
	std::string r,x;
	std::cin>>c1>>r>>c2>>x;
	if(c1==c2){std::cout<<"1";num++;}
	else std::cout<<"0";
	if(num==1&&(r[0]-'0')*10+r[1]==(x[0]-'0')*10+x[1]){std::cout<<"1";num++;}
	else std::cout<<"0";
	if(num==2&&(!((r[2]=='C'&&x[2]=='D')||(r[2]=='D'&&x[2]=='C')))){std::cout<<"1";num++;}
	else std::cout<<"0";
	if(num==3&&(r[2]+1==x[2]||x[2]+1==r[2]))std::cout<<"1";
	else std::cout<<"0";
	return 0;
} 
