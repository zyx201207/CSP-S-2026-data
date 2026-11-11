#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;	
	string k1=s1.substr(0,2);
    string k2=s2.substr(0,2);
	char p1=s1[2];
	char p2=s2[2];
	if(c1==c2){
		a=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(k1==k2){
		b=1;
	}else{
		cout<<"1000";
		return 0;
	}	
	if(p1<='C'){
		if(p2<='C'){
			c=1;
			int i=p1-'A';
			int j=p2-'A';
			if(abs(i-j)!=1){
				cout<<"1110";
				return 0;
			}else{
				cout<<"1111";
			}
		}else{
			cout<<"1100";
			return 0;
		}
				
	}
	if(p1>'C'){
		if(p2>'C'){
			c=1;
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
