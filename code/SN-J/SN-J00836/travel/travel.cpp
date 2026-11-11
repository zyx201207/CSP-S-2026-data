//白凌霄 SN-J00836 延安职业技术学院附属中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s11,s22;
	char s1,s2;
	cin>>c1>>s11>>s1>>c2>>s22>>s2;
	if(c1==c2){
		cout<<'1';
		if(s11==s22){
			cout<<'1';
			if(s1=='A' && (s2=='B' || s2=='C')){
				cout<<'1';
				if(s2=='B'){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else if(s1=='B' && (s2=='A' || s2=='C')){
		 			cout<<'1';
		 			if(s2=='A' || s2=='C'){
		 			cout<<'1';
				 	}
				 	else{
				 		cout<<'0';
					 }
				 }
			else if(s1=='C' && (s2=='A' || s2=='B')){
					 cout<<'1';
					 if(s2=='B'){
				 		cout<<'1';
				 	}
					 else{
					 	cout<<'0';
					 }
				 }
			else if(s1=='D' && s2=='F'){
				 	cout<<'1'<<'1';
				 	return 0;
			 	 }
			   	 else if(s1=='F' && s2=='D'){
					    cout<<'1'<<'1';
			}
			else{
				cout<<'0'<<'0';
			}
		}
		else
			cout<<'0'<<'0'<<'0';
		}
	else
		cout<<'0'<<'0'<<'0'<<'0';
	return 0;
}
