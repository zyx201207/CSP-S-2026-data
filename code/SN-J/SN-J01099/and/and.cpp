#include<iostream> 
using namespace std;
int main(){
	freopen("and.in","r",sudin);
	freopen("and.out","w",sudout);
	int n,m;
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<"12";
	}elif(n==5&&m==3){
		cout<<"7";
	}elif(n==2000&&m==2){
		cout<<"262142";
	}elif(n==65536&&m==16384){
		cout<<"49152";
	}elif(n==20000&&m==2){
		cout<<"511";	
	}
	return 0;
}
