#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1=0,c2=0,s1=0,s2=0;
    char a1,a2;
    cin>>c1>>s1>>a1>>c2>>s2>>a2;
    if(c1==c2&&c1!=1&&c1!=16){
    cout<<1;
    if(s1==s2){
	cout<<1;
	if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='A'&&a2=='C')||(a2=='A'&&a1=='B')||(a2=='B'&&a1=='C')||(a2=='A'&&a1=='C')||(a1=='D'&&a2=='E')||(a2=='D'&&a1=='E')){
		cout<<1;
	if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='D'&&a2=='E')||(a2=='A'&&a1=='B')||(a2=='B'&&a1=='C')||(a2=='D'&&a1=='E'))
	cout<<1;
	else
	cout<<0;	
	}else{
	    cout<<"00";
	}
	}else{
	cout<<"000";
	}
    }
    else
    cout<<"0000";
    return 0;
}
