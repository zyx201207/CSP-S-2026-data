#include<cmath>
#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define ll long long

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string S1=s1.substr(0,2);
	string S2=s2.substr(0,2);
	
	string S3=s1.substr(2);
	string S4=s2.substr(2);
	
	bool flag1=0,flag2=0,flag3=0;
	
	if(c1==c2){
		cout<<1;
		flag1=1;
	}else cout<<0;
	
	if(flag1 && S1==S2){
		cout<<1;
		flag2=1;
	}else cout<<0;
	
	if(flag2 && (S3>="A" && S3<="C") && (S4>="A" && S4<="C")){
		cout<<1;
		flag3=1;
	}else if(flag2 && (S3>="D" && S3<="F") && (S4>="D" && S4<="F")){
		cout<<1;
		flag3=1;
	}else cout<<0;
	
	if(flag3 && ((S3=="A"&&S4=="B")||(S3=="B"&&S4=="C")||(S3=="B"&&S4=="A")||(S3=="C"&&S4=="B")||(S3=="D"&&S4=="F")||(S3=="F"&&S4=="D")))
		cout<<1;
	else cout<<0;
	
	return 0;
}
