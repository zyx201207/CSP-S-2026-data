#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	if(c1!=c2){
		cout<<0;
	}else{
		cout<<1;
	}
	int num1,num2,A,B,C,D,F;
	s1="num1+'A,B,C,D,F'";
	s2="num2+'A,B,C,D,F'";
	if(num1!=num2){
		cout<<0;
	}else{
		cout<<1;
	}
	if(s1[A]&&s2[B] || s1[A]&&s2[C] || s1[B]&&s2[C] || s1[D]&&s2[F] ){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[A]&&s2[B] || s1[B]&&s2[C] || s1[D]&&s2[F]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}