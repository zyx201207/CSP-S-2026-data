#include<iostream>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	int a,b,e,f;
	string c,d;
	cin>>a>>c>>b>>d;
	e='D'+0;
    if(c[2]+0>=e){
    	e=1;
	}else{
		e=0;
	}f='D'+0;
    if(d[2]+0>=f){
    	f=1;
	}else{
		f=0;
	}
	if(a==b){
		cout<<"1";
		if(c[0]==d[0] and c[1]==d[1]){
			cout<<"1";
			if(e==f){
				cout<<"1";
				if(c[2]+0==d[2]+1 or c[2]+0==d[2]-1){
					cout<<"1";
				}else{
				    cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
} 
