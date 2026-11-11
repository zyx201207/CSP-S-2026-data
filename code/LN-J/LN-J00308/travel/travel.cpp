#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    cin>>a>>c;
    string b,d;
    cin>>b>>d;
    if(a[1]-'0'==b[1]-'0'&&a[0]-'0'==b[0]-'0'){
        cout<<"1";
    }else{

        cout<<"0000";
        return 0;
    }
    if(c[0]-'0'==d[0]-'0'&&c[1]-'0'==d[1]-'0'){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(c[2]=='A'&&d[2]=='B'||d[2]=='C'){
        cout<<"1";
    }else if(c[2]=='B'&&d[2]=='A'||d[2]=='C'){
        cout<<"1";
    }else if(c[2]=='C'&&d[2]=='B'||d[2]=='A'){
        cout<<"1";
    }else if(c[2]=='E'&&d[2]=='F'){
        cout<<"11";
        return 0;
    }else{
        cout<<"00";
        return 0;
    }
    if(c[2]=='A'&&d[2]=='B'){
        cout<<"1";
    }else if(c[2]=='B'&&d[2]=='C'){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
