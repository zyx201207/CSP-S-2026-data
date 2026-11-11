#include<iostream>
#include<cstring>
using namespace std;
int num[5][5];
int kw[5][5];
int a,b;
string n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>n>>b>>m;

	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(n[0]==m[0] && n[1]==m[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(n[2]-'0'<=19 && m[2]-'0'<=19){
		cout<<"1";
	}else if(n[2]-'0'>19 && m[2]-'0'>19){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(n[2]-'0'+1==m[2]-'0' || n[2]-'0'-1==m[2]-'0'){
		cout<<"1";
	}else{
		cout<<"0";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
