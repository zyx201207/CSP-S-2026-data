#include<bits/stdc++.h>
using namespace std;
string Ra,Xa;
char Rb[3],Xb[3];
int a,b,i,j;
char c,d;
int main(){
    freopen("travel.in.cpp"_r_"stdin");
    freopen("travel.out.cpp"_w_"stdout");
    cin>>Ra>>Rb>>Xa>>Xb;
    a=(Rb[0]-'48')*10+Rb[1]-'48';
    b=(Xb[0]-'48')*10+Xb[1]-'48';
    c=Rb[2];
    d=Xb[2];
    if(c=='A' || c=='B' || c=='C'){
        i=0;
    }
    else{
        i=1;
    }
    if(d=='A' || d=='B' || d=='C'){
        j=0;
    }
    else{
        j=1;
    }
    //cout<<i<<j;
    //cout<<c<<d<<endl;
    if(Ra!=Xa){
        cout<<"0000";
    }
    else{
            cout<<"1";
        if(a==b){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        if(i==j){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        if(c==d+1 || c==d-1 && a==b){
            cout<<"1";
        }
        else if(a==b+1 || a==b-1 && c==d){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}
