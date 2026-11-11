#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool fun(char x,char y){
    if(x>='A'&&x<='C'){
        if(y=='D'||y=='F')
            return false;
        else if(y>='A'&&y<='C')
            return true;
        else return false;
    }
    else if(x=='D'||x=='F'){
        if(y=='D'||y=='F')
            return true;
        else if(y>='A'&&y<='C')
            return false;
        else return false;
    }
    else return false;
}
bool answer(char x, char y){
    if(x=='A'&&y=='B')return true;
    else if((x=='B'&&y=='A')||(x=='B'&&y=='C'))return true;
    else if(x=='C'&&y=='B')return true;
    else if(x=='D'&&y=='F')return true;
    else if(y=='D'&&x=='F')return true;
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else cout<<0;

    if(a==c&&b[1]==d[1]&&b[0]==d[0]){
        cout<<1;
    }
    else cout<<0;

    if(fun(b[2],d[2])&&a==c&&b[1]==d[1]&&b[0]==d[0]){
        cout<<1;
    }
    else cout<<0;

    if(answer(b[2],d[2])&&a==c&&b[1]==d[1]&&b[0]==d[0]){
        cout<<1;
    }
    else cout<<0;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
