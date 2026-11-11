#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,h1,h2;char p1,p2;
    cin>>c1>>h1>>p1>>c2>>h2>>p2;
    if(c1!=c2){cout<<"0000";return 0;}
    if(h1!=h2){cout<<"1000";return 0;}
    if(p1=='A'||p1=='B'||p1=='C'){
        if(p2=='D'||p2=='F'){
            cout<<"1100";return 0;
        }
    }else if(p1=='D'||p1=='F'){
        if(p2!='D'&&p2!='F'){
            cout<<"1100";return 0;
        }
    }if((p1=='A'&&p2!='B')||(p1=='B'&&p2!='A')){
        cout<<"1110";return 0;
    }else if((p1=='B'&&p2!='C')||(p1=='C'&&p2!='B')){
        cout<<"1110";return 0;
    }else if((p1=='D'&&p2!='F')||(p1=='F'&&p2!='D')){
        cout<<"1110";return 0;
    }else{cout<<"1111";return 0;}
    return 0;
}
