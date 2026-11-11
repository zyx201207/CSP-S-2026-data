#include <iostream>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
		for(int i=0;i<3;i++){
			if(i<2){
				continue;
			}
			else if(s1[i]<s2[i]){
				if(s2[i]<sizeof("C")){
					cout<<"1";
				}
				
			}
			else if(s1[i]>s2[i]){
				if(s2[i]>=sizeof("D")){
					cout<<"1";
				}
			}
		}
		
	}
	return 0;
}
