#include<bits/stdc++.h>
using namespace std;

int main(){
	string c1,s1,c2,s2;
	cin >> c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout << 0;
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1])){
		cout << 1;
	}else{
		cout <<0;
	}
	if((s1=="D")&&(s2=="C")){
		cout << 1;
	}else if(s1=="C"&&s2=="D"){
		cout << 1;
		
	}else{
		cout << 0;
	}
	if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="A")){
		cout<< 1;
	}else if((s1=="C"&&s2=="B")||(s1=="B"&&s2=="C")){
		cout << 1;
	}else if((s1=="D"&&s2=="F")||(s1=="F"&&s2=="D")){
		cout << 1;
	}else{
		cout << 0;
	}	
	return 0;
}
