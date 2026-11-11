#include<bits/stdc++.h> 
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
int a1,b1,a2,b2,a3,b3;
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
		if(a1=b1){
			cout<<"1";
		} 
		 else {
			cout<<"0000";
		}
		if(a2=b2){
			cout<<"1";
		}
		else if(a2!=b2){
		cout<<"000";
		}
		if((a3='A',b3='B')||(a3='B',b3='C')||(a3='E',b3='F')){
			cout<<"111";
		}
			else{
				cout<<"00";
			}
		
	return 0;
}
