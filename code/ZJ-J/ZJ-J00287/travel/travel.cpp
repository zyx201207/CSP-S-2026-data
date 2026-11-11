#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<1;
		string s11,s21;
		s11=s1[0]+s1[1];
		s21=s2[0]+s2[1];
		if(s11==s21){
			cout<<1;
			s11=s1[2];
			s21=s2[2];
			if(s11<="C"&&s21<="C"){
				cout<<1;
				if(s11=="B"||s21=="B"){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s11>"C"&&s21>"C"){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		} 
		else cout<<"000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}