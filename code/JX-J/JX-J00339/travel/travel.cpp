#include<bits/stdc++.h>
using namespace std;
long long a,b,e,f;
string s,d,c,v;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>d>>v;

    for(int j=0;j<2;j++){
        if(c[j]==d[j]){
            a++;
        }
    }
    if(a==2){
        if(s[0]==v[0]&&s[1]==v[1]){
            b=1;
        }
    }
    if(a==2&&b==1){
        if(s[2]=='A'&&v[2]=='B'){
            e=1;
        }else if(s[2]=='A'&&v[2]=='C'){
            e=1;
        }else if(s[2]=='B'&&v[2]=='A'){
            e=1;
        }else if(s[2]=='B'&&v[2]=='C'){
            e=1;
        }else if(s[2]=='C'&&v[2]=='A'){
            e=1;
        }else if(s[2]=='C'&&v[2]=='B'){
            e=1;
        }else if(s[2]=='D'&&v[2]=='F'){
            e=1;
        }else if(s[2]=='F'&&v[2]=='D'){
            e=1;
        }

    }if(a==2&&b==1&&e==1){
        if(s[2]=='A'&&v[2]=='B'){
            f=1;
        }else if(s[2]=='B'&&v[2]=='A'){
            f=1;
        }else if(s[2]=='B'&&v[2]=='C'){
            f=1;
        }else if(s[2]=='C'&&v[2]=='B'){
            f=1;
        }else if(s[2]=='D'&&v[2]=='F'){
            f=1;
        }else if(s[2]=='F'&&v[2]=='D'){
            f=1;
        }

    }
    if(a==2){
            cout<<1;
    }else{
        cout<<0;
    }
    if(b==1){
        cout<<1;
    }else{
        cout<<0;
    }if(e==1){
        cout<<1;
    }else{
        cout<<0;
    }if(f==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
