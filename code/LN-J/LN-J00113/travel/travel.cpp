#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string s11=s1(0);
		string s12=s1[1];
		string s21=s2[0];
		string s22=s2[1];
		if(s11==s21 && s12==s22){
			string s13=s1[2];
			string s23=s2[2];
			if(s13=='F'||s23=='F'){
				if(s13-s23==1||s23-s13==1) cout<<"1111"<<endl;
				else cout<<"1100"<<endl
			}
			if(s13=='C'||s23=='C'){
				if(s13-s23==2||s23-s13==2) cout<<"1110"<<endl;
				if(s13-s23==1||s23-s13==1) cout<<"1111"<<endl;
				else cout<<"1100"<<endl;
			}
			if(s13=='B'||s23=='B'){
				if(s13-s23==1||s23-s13==1) cout<<"1111"<<endl;
				else cout<<"1100"<<endl;
			} 
		} else cout<<"1000"<<endl;
	} else cout<<"0000"<<endl;
}
