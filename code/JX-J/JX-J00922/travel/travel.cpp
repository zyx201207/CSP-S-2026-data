#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
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
    if((int(c[2])<=67&&int(d[2])<=67)||(int(c[2])>67&&int(d[2])>67)){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(int(c[2])==int(d[2])-1||int(c[2])==int(d[2])+1){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }

    return 0;
}
