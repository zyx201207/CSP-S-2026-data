#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;
    char a=x2[2],b=y2[2];
    if(x1==y1){
        cout<<1;
        if(x2[0]==y2[0]&&x2[1]==y2[1]){
            cout<<1;
            if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
                cout<<1;
                if((abs(a-b)==1)||(a=='D'&&b=='F')||(a=='F'&&b=='D')) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
