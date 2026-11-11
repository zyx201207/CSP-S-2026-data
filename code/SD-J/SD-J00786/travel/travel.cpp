#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string r1,r2,c11,c21;
	r1+=s1[0];r1+=s1[1];c1=s1[2];
	r2+=s2[0];r2+=s2[1];c2=s2[2];
	if(r1==r2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((c1<="C"&&c2<="C")||(c1>"C"&&c2>"C")){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((c1=="A"&&c2=="B")||(c1=="B"&&c2=="C")||(c1=="B"&&c2=="A")||(c1=="C"&&c2=="B")||(c1=="D"&&c2=="F")||(c1=="F"&&c2=="D")){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
