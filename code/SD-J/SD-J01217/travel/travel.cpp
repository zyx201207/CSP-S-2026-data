#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
string a_1,a_2,b_1,b_2;
int a_3,b_3;
int check1(){
	if(a_1==b_1)return 1;
	return 0;
}
int check2(){
	if(check1()){
		if(a_2==b_2)return 1;
	}
	return 0;
}
int check3(){
	if(check2()){
		if(a_3<3 && b_3<3)return 1;
		else if(a_3>=3 && b_3>=3)return 1;
	}
	return 0;
}
int check4(){
	if(check3()){
		if(abs(a_3-b_3)==1)return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a_1>>a_2>>b_1>>b_2;
	a_3=a_2[2]-'A';
	b_3=b_2[2]-'A';
	a_2.erase(2,1);
	b_2.erase(2,1);
	cout<<check1();
	cout<<check2();
	cout<<check3();
	cout<<check4();
	return 0; 
}
