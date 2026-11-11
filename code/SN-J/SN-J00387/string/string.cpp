#include<bits/stdc++.h>
//std::ifstream cin("string1.in");
//std::ofstream cout("string1.out"); 
int main(){
	int m,min=0;
	std::string s="0";
	std::cin>>m;
	int n1;
	std::string a1;
	std::cin>>n1>>a1;
	s=a1;
	for(int j=0;j<n1-1;j++)
	s=s+a1;	
	for(int i=0;i<m-1;i++){
		int n;
		std::string a;
		std::cin>>n>>a;
		for(int j=0;j<n;j++)
		s=s+a;
	}
	if(s.size()%2==0){
	for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2-1;i++,j--){
		if(s[i]!=s[j]){
			min++;
		}
	}		
	}
    else{
    	for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			min++;
		}
	}		
	}
	std::cout<<min;
	return 0;
}
