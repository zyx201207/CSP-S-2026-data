#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string x;
	string y;
	int z=1;
	int q=1;
	int z_=1;
	int q_=1;
	cin>>a;
	cin>>b;
	cin>>x;
	cin>>y;
	if(a==x){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]*10+b[1]==y[0]*10+y[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]>=65&&b[2]<=67){
		z=0;
	}
	if(y[2]>=65&&y[2]<=67){
		q=0;
	}
	if(b[2]==68||b[2]==70){
		z_=0;
	}
	if(y[2]==68||y[2]==70){
		q_=0;
	}
	if(z==0&&q==0||z_==0&&q_==0){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]-y[2]==1||y[2]-b[2]==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
