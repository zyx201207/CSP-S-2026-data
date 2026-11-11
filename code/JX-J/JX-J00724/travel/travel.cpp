#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    int p=(int(b[0]-'0'))*10+int(b[1]-'0');
    int q=(int(d[0]-'0'))*10+int(d[1]-'0');
    if(p==q){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='D'&&d[2]=='F'){
        cout<<"11";
        return 0;
    }
    else if(b[2]=='F'&&d[2]=='D'){
        cout<<"11";
        return 0;
    }
    else if(b[2]=='A'&&(d[2]=='B'||d[2]=='C'))   cout<<"1";
    else if(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))   cout<<"1";
    else if(b[2]=='C'&&(d[2]=='A'||d[2]=='B'))   cout<<"1";
    else    cout<<"0";
    if(b[2]=='A'&&d[2]=='C')    cout<<"0";
    else if(b[2]=='C'&&d[2]=='A')   cout<<"0";
    else if(b[2]=='C'&&d[2]=='D')   cout<<"0";
    else if(b[2]=='D'&&d[2]=='C')   cout<<"0";
    else    cout<<"1";
    return 0;

}
