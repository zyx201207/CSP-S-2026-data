#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f=1;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	string n,m;
	f=1;
	n=b.substr(0,2);
	m=d.substr(0,2);
	for(int i=0;i<2;i++){
		if(n[i]!=m[i]){
			f=0;
			break;
		}
	}
	if(f)cout<<"1";
	else{
		cout<<"000";
		return 0; 
	} 
	n=b.substr(2,3);
	m=d.substr(2,3);
	if(n>="A"&&n<="C"&&m>="A"&&m<="C"){
		cout<<"1";
	}
	else if(n>="D"&&n<="F"&&m>="D"&&m<="F"){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(n=="A"&&m=="B")cout<<1;
	else if(n=="B"&&m=="C")cout<<"1";
	else if(n=="D"&&m=="F")cout<<"1";
	else if(m=="A"&&n=="B")cout<<"1";
	else if(m=="B"&&n=="C")cout<<"1";
	else if(m=="D"&&n=="F")cout<<"1";
	else cout<<"0";
	return 0;
} 
