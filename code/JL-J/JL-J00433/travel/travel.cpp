#include<bits/stdc++.h>
using namespace std;
string sa;
char sb[4];
string pa;
char pb[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>sa;
    for(int i=1;i<=3;i++){
        cin>>sb[i];
    }
    cin>>pa;
    for(int i=1;i<=3;i++){
        cin>>pb[i];
    }
    int a=(sb[1]-'0')*10+(sb[2]-'0');
    int b=(pb[1]-'0')*10+(pb[2]-'0');
    if(sa==pa){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(a==b){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(sb[3]>='A'&&pb[3]>='A'&&sb[3]<='C'&&pb[3]<='C'||sb[3]>='D'&&pb[3]>='D'&&sb[3]<='F'&&pb[3]<='F'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(sb[3]=='A'&&pb[3]=='B'||sb[3]=='B'&&pb[3]=='A'||sb[3]=='B'&&pb[3]=='C'||sb[3]=='C'&&pb[3]=='B'||sb[3]=='D'&&pb[3]=='F'||sb[3]=='F'&&pb[3]=='D'){
        cout<<"1";
        return 0;
    }
    else{
        cout<<"0";
        return 0;
    }
}
