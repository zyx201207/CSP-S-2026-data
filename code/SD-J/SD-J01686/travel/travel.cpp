#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(c1==c2){
		if(s1[0]+s1[1] == s2[0]+s2[1]){
			if( (a>='A' && a<='C') && (b>='A' && b<='C') ){
				if(abs(a-b)==1)	cout<<"1111"<<endl;
				else cout<<"1110"<<endl;				
			}else if(a>'C' && b>'C'){	
				if(abs(a-b)==1)	cout<<"1111"<<endl;
				else cout<<"1110"<<endl;
			}else{
				cout<<"1100"<<endl;
			}
		}else{
			cout<<"1000"<<endl;	
		}
	}else{
		cout<<"0000"<<endl;	
	}
	
	return 0;
}
