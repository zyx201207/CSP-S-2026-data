#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int e=b[0],f=b[1],g=d[0],h=d[1];
	if(e==g&&f==h){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int j=b[2],k=d[2];
	if(1==1){
	if(j<68&&j>64){
		if(k<68&&k>64){
			cout<<"1";
		}
	}
	if(j>67&&j<71){
		if(k>67&&k<71){
			cout<<"1";
		}
	}
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='C'){
		cout<<"00";
		return 0;
	}
	if(j==68&&k==70){
		cout<<"1";
	}
	if(j==70&&k==68){
		cout<<"1";
    }
    if(j==67&&k==68){
		cout<<"0";
		return 0;
	}
	if(j==68&&k==67){
		cout<<"0";
		return 0;
	}
	if(abs(j-k)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}//synb
