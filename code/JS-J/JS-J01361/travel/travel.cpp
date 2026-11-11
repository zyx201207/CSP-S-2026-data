#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        char x=s1[2],y=s2[2];
        string a=s1.substr(0,2),b=s2.substr(0,2);
        int c,d;
        c=(a[0]-'0')*10+(a[1]-'0');
        d=(b[0]-'0')*10+(b[1]-'0');
        if(c==d){
            cout<<"1";
            if(x=='A'||x=='B'||x=='C'){
                if(y=='A'||y=='B'||y=='C')cout<<"1";
                else cout<<"0";
            }else{
                if(y=='D'||y=='E')cout<<"1";
                else cout<<"0";
            }
        }else cout<<"00";
        if(y==x&&(c==d+1||c==d-1))cout<<"1";
        else if(c==d){
            if((x=='A'||x=='C')&&y=='B')cout<<"1";
            else if(x=='B'&&(y=='A'||y=='C'))cout<<"1";
            else if(x=='D'&&y=='E')cout<<"1";
            else if(x=='E'&&y=='D')cout<<"1";
            else cout<<"0";
        }else cout<<"0";
    }else cout<<"0000";
    return 0;
}
