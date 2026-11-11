#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char a3,b3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    if(a1!=b1){
        cout<<"0000\n";
    }
    else if(a2!=b2){
        cout<<"1000\n";
    }
    else if(((a3=='A'||a3=='B'||a3=='C') &&(b3=='D'||b3=='F'))||((b3=='A'||b3=='B'||b3=='C')&&(a3=='D'||a3=='F'))){
        cout<<"1100\n";
    }
    else if((a3=='A'&&b3=='C')||(a3=='C'&&b3=='A')){
        cout<<"1110\n";
    }
    else{
        cout<<"1111\n";
    }
    fclose("travel.in");
    fclose("travel.out");
    return 0;
}
