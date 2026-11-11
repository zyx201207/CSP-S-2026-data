#include<bits/stdc++.h>
using namespace std;



int main(){
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;
	
	
	if(c1!=c2){
		cout<<"0000"<<endl;
	}else{
		int p1=(s1[0]-'0')*10+(s1[1]-'0');
		int p2=(s2[0]-'0')*10+(s2[1]-'0');
		
		if(p1!=p2){
			cout<<"1000"<<endl;
		}else{
			char w1=s1[2];
			char w2=s2[2];
			
			if((w1<='C'&&w2>='D')||(w1>='D'&&w2<='C')){
				cout<<"1100"<<endl;
			}else{
				if(abs(w1-w2)!=1){
					cout<<"1110"<<endl;
				}else{
					cout<<"1111"<<endl;
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	return 0;
}



//By Ge Donghan
//CSP-J P1 travel
