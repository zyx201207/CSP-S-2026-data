#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2,b1,b2;
string s1,s2,n1,n2,z1,z2;
int main(){
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        n1[i]=s1[i];
        n2[i]=s2[i];
    }
    z1=s1[2];
    z2=s2[2];
    if(z1=="A"){
    	b1=1;
	}
	if(z1=="B"){
    	b1=2;
	}if(z1=="C"){
    	b1=3;
	}if(z1=="D"){
    	b1=4;
	}if(z1=="F"){
    	b1=5;
	}
	if(z2=="A"){
    	b2=1;
	}
	if(z2=="B"){
    	b2=2;
	}if(z2=="C"){
    	b2=3;
	}if(z2=="D"){
    	b2=4;
	}if(z2=="F"){
    	b2=5;
	}
    if(z1=="A"||z1=="B"||z1=="C"){
        a1=1;
    }else a1=2;
    if(z2=="A"||z2=="B"||z2=="C"){
        a2=1;
    }else a2=2;
    if(c1==c2){
        cout<<"1";
        if(n1==n2){
            cout<<"1";
            if(a1==a2){
                cout<<"1";
                if(b1-b2==1||b1-b2==-1){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
