#include<bits/stdc++.h>
using namespace std;
bool FCB(char a,char b){
	if(a<='C'&&b<='C')return true;
	if(a>='D'&&b>='D')return true;
	return false;
}
bool ARS(char a,char b){
	char f=min(a,b);
	char g=max(a,b);
	if(char(int(f)+1)==g)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;//≥µœ· 
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	string a2=a1.substr(0,2);//≈≈ 
	string b2=b1.substr(0,2);
	char a3=a1[2];//¡– 
	char b3=b1[2];
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(a2==b2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(FCB(a3,b3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(ARS(a3,b3)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

/*
π¿∑÷100 
*/
