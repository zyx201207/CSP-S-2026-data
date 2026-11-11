#include <iostream>
using namespace std;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	int a[5],c[5];
	int b[5],d[5];
	for(int i = 0;i < 3;i++){
		cin >> a[i];
		}
	
	for(int i = 0;i < 4;i++){
		cin >> b[i];
		}
	for(int i = 0;i < 3;i++){
		cin >> c[i];
		}
	for(int i = 0;i < 4;i++){
		cin >> d[i];
		}
	if(a[1] == c[1]){
		
			cout << "1";
		}
		else{
			for(int i = 0;i < 4;i++){
				cout << "0";
			}
			return 0;}
		
	if((b[0]==d[0])||(b[1]==d[1])){
		cout << "1";
	}
	else{
		for(int i = 0;i < 3;i++){
				cout << "0";
			}
		return 0;}
	if((b[2]=="C" && b[2]== "D")||(d[2]=="C" && d[2]== "D")){
		for(int i = 0;i < 2;i++){
			cout << "0";
		}
		return 0;
	}
	else{
		cout << "1";}
	if((b[2]=="A"||d[2]=="B")&&(b[2]=="B"||d[2]=="C")||(b[2]=="D"||d[2]=="F"){
		cout << "1";
	}
	else{
		cout << "0";
	}
	
	
	
	
	
	
	
	return 0;
}
