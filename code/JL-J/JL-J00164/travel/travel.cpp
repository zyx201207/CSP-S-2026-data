#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<"0000"<<endl;
    else if(b.substr(0,2)!=d.substr(0,2))cout<<"1000"<<endl;
    else if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C'))cout<<"1100"<<endl;
    else if(abs(b[2]-d[2])==1)cout<<"1111"<<endl;
    else cout<<"1110"<<endl;
    return 0;
}