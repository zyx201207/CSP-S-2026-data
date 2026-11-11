#include<bits/stdc++.h>
using namespace std;
int a1,a2;
char b1,b2,b3,c1,c2,c3;
int l1,l2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1;
    cin>>b1;
    cin>>b2;
    cin>>b3;
    cin>>a2;
    cin>>c1;
    cin>>c2;
    cin>>c3;
    if(a1==a2)cout<<"1";
    else{cout<<"0000";return 0;}
	
	if(b1 ==c1&&b2==c2)cout<<"1";
	else{cout<<"000";return 0;}
	
	if(b3=='F'||b3=='D')l1=1;
	else l1=0;
	if(c3=='F'||c3=='D')l2=1;
	else l2=0;
	
	if(l1==l2)cout<<"1";
	else{cout<<"00";return 0;}
	
	if(l1==1){
		cout<<"1";
		return 0;
	}else{
		if(b3=='B'||c3=='B'){cout<<"1";return 0;}
		else{cout<<"0";return 0;}
	}
    return 0;
}
