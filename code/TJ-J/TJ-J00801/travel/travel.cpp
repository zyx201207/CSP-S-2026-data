#include <bits/stdc++.h>

int c1,c2;
std::string s1,s2;

int main(){
	
	std::fstream in;
	in.open("travel.in");
	std::ofstream out;
	out.open("travel.out");
	
	in>>c1>>s1>>c2>>s2;
	
	int is1=0,is2=0;
	is1=s1[2]-'A';
	is2=s2[2]-'A';
	
	//std::cout<<c1<<s1<<c2<<s2;
	if(c1==c2) {
		out<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			out<<1;
		
			if((is1<3&&is2<3) || (is1>2&&is2>2)){
				out<<1;
			}else{
				out<<0;
			}
			if((is1-is2==1 || is1-is2==-1) && is1!=2 && is2!=3){
				out<<1;
			}else{
				out<<0;
			}
		}else{
			out<<0<<0<<0;
		}
	}else{
		out<<0<<0<<0<<0;
	}


	
//	std::cout<<"\n"<<is1<<is2<<"\n";



	

	
	out.close();
	return 0;
}
