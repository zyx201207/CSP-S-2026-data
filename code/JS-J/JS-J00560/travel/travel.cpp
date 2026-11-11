#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<'1';
        int x=b[0]*10+b[1],y=d[0]*10+d[1];
        char g=b[2],h=d[2];
        if(x==y){
            cout<<'1';
            int u,o;
            if(g=='D'||g=='F')u=0;
            else u=1;
            if(h=='D'||h=='F')o=0;
            else o=1;
            if(u==o){
                cout<<'1';
                if(abs((int)(g-h))==1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
