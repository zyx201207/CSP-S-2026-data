#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,su1,su2;
bool check(char ch1,char ch2){
	if('A'<=ch1&&ch1<='C'){
		if('A'<=ch2&&ch2<='C')return 1;
		else return 0;
	}
	else{
		if('A'<=ch2&&ch2<='C')return 0;
		else return 1;
	}
}
bool check1(char ch1,char ch2){
	if('A'<=ch1&&ch1<='C'){
		if('A'<=ch2&&ch2<='C'){
			if(abs((int)ch1-(int)ch2)==1)return 1;
			else return 0;
		}
		else return 0;
	}
	else{
		if('A'<=ch2&&ch2<='C')return 0;
		else{
			if(abs((int)ch1-(int)ch2)==1)return 1;
			else return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else cout<<"0";
	
	su1=s1[0]+s1[1];
	su2=s2[0]+s2[1];
	if(su1==su2&&c1==c2)cout<<"1";
	else cout<<"0";
	
	if(su1==su2&&c1==c2)cout<<check(s1[2],s2[2]);
	else cout<<"0";
	
	if(su1==su2&&c1==c2)cout<<check1(s1[2],s2[2]);
	else cout<<"0";
	
	return 0;
}