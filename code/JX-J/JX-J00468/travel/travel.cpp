#include<bits/stdc++.h>
using namespace std;
int a,b,sum1=0,sum2=0;
char zm1,zm2;
string a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    getline(cin,a1);
    cin>>b;
    getline(cin,b1);
    sum1=a1[0]*10+a1[1];
    sum2=b1[0]*10+b1[1];
    zm1=a1[2];
    zm2=b1[2];
    if(a==b){
        cout<<"1";
        if(sum1==sum2){
            cout<<"1";
            if((zm1=='A'||zm1=='B'||zm1=='C')&&(zm2=='A'||zm2=='B'||zm2=='C')){
                cout<<"1";
            }
            if((zm1=='F'||zm1=='D')&&(zm2=='D'||zm2=='F')){
                cout<<"1";
            }
        }
        if((zm1=='C'&&zm2=='D')&&(zm1=='D'&&zm2=='C'){
        cout<<"0";
    }
    else if(zm1==zm2+1||zm2==zm1+1){
        cout<<"1";
    }
    }
    else {
        cout<<"0"<<"0"<<"0";
    }
    return 0;
}
