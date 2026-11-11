//SN-J00594 张源朔 西安市高新第二初级中学 621123201306230018

#include <bits/stdc++.h>

using namespace std ;

int c1,c2 ;
string s1,s2 ;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2 ;
	//part 1
	bool check1=0;
	if(c1==c2) {
		cout<<"1" ;
		check1=1;
	}
	else{
		cout<<"0" ;
	}
	//part 2
	bool check2=0; 
	if(s1[0]==s2[0] && s1[1]==s2[1] && check1==1) {
		cout<<"1" ;
		check2=1;
	}
	else{
		cout<<"0" ;
	}
	//part 3
	bool check3=0;
	if(((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')) && check2==1) {
		cout<<"1" ;
		check3=1;
	}
	else{
		cout<<"0" ;
	}
	//part 4
	if(abs (s1[2]-s2[2])==1 && check3==1) {
		cout<<"1" ;
	}
	else{
		cout<<"0" ;
	}
    //撒花☆(￣▽￣)/ 
	return 0 ;
}
