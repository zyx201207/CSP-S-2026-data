#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else cout<<"0";
    string e="",f="";
    for(int i=0;i<b.size()-1;i++){
        e=e+b[i];
        f=f+d[i];
    }
    if(a==c&&e==f) cout<<"1";
    else cout<<"0";
    if(a==c&&e==f&&b[b.size()-1]>='A'&&b[b.size()-1]<='C'&&d[d.size()-1]>='A'&&d[d.size()-1]<='C'||b[b.size()-1]>='D'&&b[b.size()-1]<='F'&&d[d.size()-1]>='D'&&d[d.size()-1]<='F') cout<<"1";
    else cout<<"0";
    if(a==c&&e==f&&b[b.size()-1]>='D'&&b[b.size()-1]<='F'&&d[d.size()-1]>='D'&&d[d.size()-1]<='F') cout<<"1";
    else if(a==c&&b[b.size()-1]=='C'||b[b.size()-1]=='D'&&d[d.size()-1]=='C'||d[d.size()-1]=='D') cout<<"0";
    else if(a==c&&e==f&&b[b.size()-1]-d[d.size()-1]==1||d[d.size()-1]-b[b.size()-1]==1) cout<<"1";
    else cout<<"0";


    return 0;
}
