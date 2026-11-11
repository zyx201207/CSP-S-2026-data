#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[0],b=s1[1],c=s1[2],
	d=s2[0],e=s2[1],f=s2[2];
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	if(a==d&&b==e){
		cout<<'1';
	}else{
		cout<<'0'<<'0'<<'0';
		return 0;
	}
	if(('A'<=c&&c<='C'&&'A'<=f&&f<='C')||
	('D'<=c&&c<='E'&&f>='D'&&f<='E')
	&&a==d&&b==e){
		cout<<'1';
	}else{
		cout<<'0'<<'0';
		return 0;	
	}
	if((c=='A'&&f=='B')||(c=='B'&&f=='C')||(c=='D'&&f=='F')){
		cout<<'1';
	}else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
