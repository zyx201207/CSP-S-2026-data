#include<bits/stdc++.h>
std::string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		std::cout<<0<<0<<0<<0<<'\n';
		return 0;
	}
	std::cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		std::cout<<0<<0<<0<<'\n';
		return 0;
	}
	std::cout<<1;
	if(s1[2]>='D'&&s2[2]>='D'){
		std::cout<<11<<'\n';
		return 0;
	}else if(s1[2]<='C'&&s2[2]<='C'){
		std::cout<<1;
	}else{
		std::cout<<0<<0<<'\n';
		return 0;
	}
	if(abs(s1[2]-'A'-s2[2]+'A')==1){
		std::cout<<1<<'\n';
		return 0;
	}
	std::cout<<0<<'\n';
	return 0;
}

