#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int fx,sx,fr,sr;
    char tx,tr;
    scanf("%d %d%c %d %d%c",&fx,&sx,&tx,&fr,&sr,&tr);
    if(fx==fr){
        cout<<"1";
        if(sx==sr){
            cout<<"1";
            if(tx>='D'&&tr>='D')
                cout<<"11";
            else if(tx<='C'&&tr<='C'){
                cout<<"1";
                if(abs((int)(tx-tr))==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
