#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=c[i])
            flag=1;
    }
    if(flag){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(b[0]==d[0]&&b[1]==d[1])
        cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
        cout<<'1';
    else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
        cout<<"11";
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(b[2]-d[2])==1)
        cout<<'1';
    else
        cout<<'0';
    return 0;
}
