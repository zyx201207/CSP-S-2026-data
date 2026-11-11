#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int t;
    char bb,dd;
    cin>>a>>b>>c>>d;
    bb=b[b.size()-1];
    dd=d[d.size()-1];
    if(a!=c){
        cout<<"000";
    }
    else{
        cout<<1;
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<1;
            t=1;
            if((dd<='C' && bb>='D') || (bb<='C' && dd>='D')){
                cout<<0;
            }
            else{
                cout<<1;
            }
        }
        else{
            cout<<"00";
            t=0;
        }
    }
    if(t && (   (abs(int(dd-bb))==1 && (bb!='D' && dd!='D')) || (dd=='D' && bb=='F') || (dd=='F' && bb=='D')    )){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
