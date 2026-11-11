#include<bits/stdc++.h>
using namespace std;
int ok1,ok2;
void check(char x,char y){
    if(x=='A'){
        if(y=='B'){
            ok1=1,ok2=1;
        }else if(y=='C'){
            ok1=1;
        }
    }else if(x=='B'){
        if(y=='A'){
            ok1=1,ok2=1;
        }else if(y=='C'){
            ok1=1,ok2=1;
        }
    }else if(x=='C'){
        if(y=='B'){
            ok1=1,ok2=1;
        }else if(y=='A'){
            ok1=1;
        }
    }
    else if(x=='D'){
        if(y=='E'){
            ok1=1,ok2=1;
        }
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    int r=(r2[0]-'0')*10+r2[1];
    int x=(x2[0]-'0')*10+x2[1];
    char a=r2[2],b=x2[2];
    if(r1==x1) {
        cout<<1;
        if(r==x){
            cout<<1;
            check(a,b);
            cout<<ok1<<ok2;
        }else {
            cout<<"000";
        }
    }
    else {
        cout<<"0000";
    }

    return 0;
}
