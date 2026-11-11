#include<bits/stdc++.h> 
using namespace std;

int main(){
     int a,b,c,d;
     cin>>a>>b>>c>>d;
     for(int i;i<=a;i++){
     	for(int j;j<=b;j++){
     		for(int q;q<=c;q++){
     			for(int x;x<=d;x++){
     				 if(a=i){
	 	cout<<"1";
	 }else{
	 	cout<<"0";
	 }
	 if(b=j){
	 	cout<<"1";
	 }else{
	 	cout<<"0";
	 }
	 i++;							
				 }
			 }
		 }
	 }
cout<<i;
	return 0;
}
