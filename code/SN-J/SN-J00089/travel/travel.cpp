#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long c1,c2,c,d;
	string s1,s2;
	cin>>c1>>c>>s1>>c2>>d>>s2;
	if(c1==c2){
		cout<<"1";
		if(c==d){
			cout<<"1";
			if(s1=="A"&&s2!="D"&&s2!="F"||s1=="B"&&s2!="D"&&s2!="F"||s1=="C"&&s2!="D"&&s2!="F"||s1=="D"&&s2!="A"&&s2!="B"&&s2!="C"||s1=="F"&&s2!="A"&&s2!="B"&&s2!="C"){
				cout<<"1";
				if(s1=="A"&&s2=="B"||s1=="B"&&s2=="A"||s1=="B"&&s2=="C"||s1=="C"&&s2=="B"||s1=="D"&&s2=="F"||s1=="F"&&s2=="D"){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
