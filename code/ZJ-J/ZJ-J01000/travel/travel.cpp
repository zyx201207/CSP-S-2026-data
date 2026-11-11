#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check(char c){
	if(c=='A' || c=='B' || c=='C'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	int n=(s2[0]-'0')*10+(s2[1]-'0');
	int m=(s4[0]-'0')*10+(s4[1]-'0');
	char c1=s2[2],c2=s4[2];
	if(n==m){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(check(c1)==check(c2)){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	int num1,num2;
	num1=c1-'A',num2=c2-'A';
	if(num1-num2==1 || num2-num1==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
