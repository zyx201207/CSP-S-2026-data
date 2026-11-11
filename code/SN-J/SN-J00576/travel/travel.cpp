#include<iostream>
#include<string>
//#include<bits/c++h.std>
#define ll long long
#define PID " "
#define FIN freopen(PID ".in","r",stdin)
#define FOU freopen(PID ".out","r",stdout)
using namespace std;
int main(){
	//FIN;FOU;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
	if(b[2]!=d[2]||b[1]!=d[1]){
	cout<<"1000";
	}else{
	if(b[3]!='D'&&b[3]!='F'){
		if(d[3]=='D'||d[3]=='F')cout<<"1100";
	}else{
	if(d[3]!='D'&&d[3]!='F'){
		if(b[3]=='D'||b[3]=='F')cout<<"1100";
	}}}}
	/*else{
	if(b[3]=='D'&&d[3]=='F')cout<<"1110";
	else{
	if(b[3]=='A'&&d[3]=='B'){cout<<"1110";
	}
	else{
	if(b[3]=='B'&&d[3]=='C'){cout<<"1110";
	}
	else{
	if(b[3]=='B'&&d[3]=='A'){cout<<"1110";
	}
	else{
	if(b[3]=='C'&&d[3]=='A'){cout<<"1110";
	}
	}}}}else{
	if(b[3]=='F'&&d[3]=='D')cout<<"1110";
	else{
	cout<<"1111";*/
	return 0;
}

