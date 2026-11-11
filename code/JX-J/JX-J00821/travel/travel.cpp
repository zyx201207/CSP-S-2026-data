#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;

    cin>>a>>b>>c>>d;
    if(a==b){
        cout<<1;

    }else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==d[0]&&c[1]==d[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    bool s=(c[2]<='C'&&d[2]<='C'),m=(c[2]>='D'&&d[2]>='D');
    if(s==1||m==1){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }if(m==1||(s==1&&abs(int(c[2]))-(int(d[2])==1))){
        cout<<1;

    }else{
        cout<<"0";
        return 0;
    }



    return 0;

}
