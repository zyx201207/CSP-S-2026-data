#include<bits/stdc++.h>
using namespace std;\
string a,b,c,d,e,f,g,h;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000"<<endl;return 0;
    }e=b[0]+b[1];
    f=d[0]+d[1];
    g=b[2];
    h=d[2];
    if(e!=f){
        cout<<"1000"<<endl;return 0;
    }
    if(g=="E"){
		if(h=="D"){
			cout<<"1111"<<endl;
		}else{
			cout<<"1100"<<endl;
		}return 0;
	}if(h=="E"){
		if(g=="D"){
			cout<<"1111"<<endl;
		}else{
			cout<<"1100"<<endl;
		}return 0;
	}if(g=="D"){
		if(h=="E"){
			cout<<"1111"<<endl;
		}else{
			cout<<"1100"<<endl;
		}return 0;
	}if(h=="D"){
		if(g=="E"){
			cout<<"1111"<<endl;
		}else{
			cout<<"1100"<<endl;
		}return 0;
	}
	if(g=="A"||h=="A"){
		if(h=="C"||g=="C"){
			cout<<"1110"<<endl;
		}else{
			cout<<"1111"<<endl;
		}return 0;
	}else{
		cout<<"1111"<<endl;
	}
    return 0;
}
