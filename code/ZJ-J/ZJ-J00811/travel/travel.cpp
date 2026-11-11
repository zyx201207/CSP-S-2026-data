#include<iostream>
#include<string>
using std::iostream;
using std::string;
using std::cin;
using std::cout;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rw,re,xw,xe;
	int n=0,m=0,a=0,b=0;
	cin>>rw>>re>>xw>>xe;
	if(rw==xw){
		cout<<"1";
		n=1;
	}else{
		cout<<"0";
	}
	if(n==1&&re[0]==xe[0]&&re[1]==xe[1]){
		cout<<"1";
		m=1;
	}else{
		cout<<"0";
	}
	if(xe[2]>='A'&&xe[2]<='C'&&re[2]>='A'&&re[2]<='C'&&m==1){
		cout<<"1";
		a=1;
	}else if(re[2]>='D'&&re[2]<='E'&&m==1&&xe[2]>='D'&&xe[2]<='E'){
		cout<<"1";
		b=1;
	}
	else{
		cout<<"0";
	}
	if(a==1){
		if(xe[2]+1==re[2]||re[2]+1==xe[2]){
			cout<<"1";
		}
	}
	else if(b==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
