#include <bits/stdc++.h>


int n;
long long num_n[30];
std::string str;

int Nnum=0;
bool flag=false;

int numSort[30];



std::string re(std::string str_s){
	int s=str_s.size();
	
	std::string str_re;
	
	for(int i=s-1;i>=0;i--){
		str_re+=str_s[i];
	}
	
	return str_re;
}

int comp(std::string str1,std::string str2){
	int s1=str1.size();
	long long count=0;
	
	str1=re(str1);
	
	for(int i=0;i<s1;i++){
		if(str1[i]!=str2[i]){
			count++;
		}
	}
	
	std::cout<<count;
	return 0;
}



int main(){
	
	std::ifstream in;
	in.open("string3.in");
	std::ofstream out;
	out.open("string.out");
	
	in>>n;
	for(int i=0;i<n;i++){
		int numN=0;
		char Cnum;
		in>>numN;
		in>>Cnum;
		num_n[Cnum-'a']+=numN;
		
		Nnum+=numN;
		
		for(int j=0;j<numN;j++){
			str+=Cnum;
		}
	}
	
	//std::cout<<num_n[0]<<num_n[1];
	
	//std::cout<<str;
	if(Nnum%2==0){
		flag=true;
		long long num_zhong=Nnum/2;
		std::string str1;
		std::string str2;
		
		for(long long i=0;i<num_zhong;i++){
			str1+=str[i];
		}
		for(long long i=num_zhong;i<Nnum;i++){
			str2+=str[i];
		}
		
		//std::cout<<str1<<" "<<str2<<" ";
		out<<comp(str1,str2);
		
	}else{
		flag=false;
		long long num_zhong=Nnum/2;
		std::string str1;
		std::string str2;
		
		for(long long i=0;i<num_zhong;i++){
			str1+=str[i];
		}
		for(long long i=num_zhong+1;i<Nnum;i++){
			str2+=str[i];
		}
		
		//std::cout<<str1<<" "<<str2;
		out<<comp(str1,str2);
		
	}
	
	
	
	in.close();
	out.close();
	return 0;
}
