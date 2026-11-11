#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<"1";
            int bway=(b[2]>='D');
            int dway=(d[2]>='D');
            if(bway==dway){
                cout<<"1";
                if(abs(b[2]-d[2])==1){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else{
        cout<<"0000";
    }
}
//finish at 8:40