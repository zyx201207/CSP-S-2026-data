#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<1;
            char c1=b[2],d1=d[2];
            if(c1>='A' && c1<='C' && d1>='A' && d1<='C'){
                cout<<1;
                if(c1==d1+1 or c1==d1-1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if(c1>='D' && c1<='F' && d1>='D' and d1<='F'){
                cout<<1;
                if(c1==d1+2 or c1==d1-2){
                    cout<<1;
                }else cout<<0;
            }else{
                cout<<"00";
            }
        }else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
