#include<iostream>//4,101
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if (a1==a2){//1
		cout<<'1';
	}else{
		cout<<'0';
	}
	if (a1==a2){
		if (b1[1]==b2[1]){//2
		cout<<'1';
	}else{
		cout<<'0';
		}
	}else{
		cout<<'0';
	}
	
	//3,两个条件 
	if (a1==a2){
		if (b1[1]==b2[1]){
			if (b1[2]>='A' && b1[2]<='C' && b2[2]>='A' && b2[2]<='C'){
				cout<<'1';
			}else if (b1[2]>='D' && b1[2]<='F' && b2[2]>='D' && b2[2]<='F'){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}else{
			cout<<'0'; 
		}
	}else{
		cout<<'0';
	}
	
//	if (b1[2]>='A' && b1[2]<='C' &&)
	if (a1==a2){
		if (b1[1]==b2[1]){
			if (b1[2]>='A' && b1[2]<='C' && b2[2]>='A' && b2[2]<='C'){//4
				if ((char)(b1[2]+1)==b2[2] ||(char)(b2[2]+1)==b1[2]){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if (b1[2]>='D' && b1[2]<='F' && b2[2]>='D' && b2[2]<='F'){//没有E
				if ((char)(b1[2]+2)==b2[2] ||(char)(b2[2]+2)==b1[2]){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else {
				cout<<'0';
			}	
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
	}
	return 0;
	//cout<<(char)('b'+2);!!!!!!!!!!!!!
}
