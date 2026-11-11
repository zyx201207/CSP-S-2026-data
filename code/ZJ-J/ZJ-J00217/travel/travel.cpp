#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1;
		string num1,num2;
		num1+=s1[0];
		num1+=s1[1];
		num2+=s2[0];
		num2+=s2[1];
		if(num1!=num2){
			cout<<"000";
		}
		else{
			cout<<1;
			char x=s1[2],y=s2[2];
			if(x<='C'&&y<='C'){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(x>='D'&&y>='D'){
				cout<<11;
			}
			else{
				cout<<"00";
			}
		}
	}
	
	
	return 0;
}