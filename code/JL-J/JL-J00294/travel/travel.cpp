#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int xchexiang,rchexiang;
    int xpai,rpai;
    char xseat,rseat;
    cin>>xchexiang>>xpai>>xseat;
    cin>>rchexiang>>rpai>>rseat;
    if(xchexiang==rchexiang){
        cout<<1;
        if(xpai==rpai){
            cout<<1;
            if((xseat<='C'&&rseat<='C')||(xseat>='D'&&rseat>='D')){
                cout<<1;
                if(xseat-rseat==1||xseat-rseat==-1) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else cout<<"00"<<endl;
        }
        else cout<<"000"<<endl;
    }
    else cout<<"0000"<<endl;
    return 0;
}
