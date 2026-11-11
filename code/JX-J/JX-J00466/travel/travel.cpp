#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]*10+a[1]==1 || a[0]*10+a[1]==16 || b[0]*10+b[1]==1 || b[0]*10+b[1]==16)
        cout<<0<<0<<0<<0;
    else if(a==c){
       cout<<1;
       if(b[1]+b[0]*10==d[1]+b[0]*10){
            cout<<1;
            if((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='A') || (b[2]=='A' && d[2]=='C') || (b[2]=='C' && d[2]=='A') || (b[2]=='C' && d[2]=='B') || (b[2]=='B' && d[2]=='C') || (b[2]=='D' && d[2]=='E') || (b[2]=='E' && d[2]=='D')){
                cout<<1;
                if((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='C') || (b[2]=='D' && d[2]=='E') || (b[2]=='B' && d[2]=='A') || (b[2]=='C' && d[2]=='B') || (b[2]=='E' && d[2]=='D')){
                    cout<<1;
                }else cout<<0;
            }else cout<<0<<0;
       }else cout<<0<<0<<0;
    }else{
        cout<<0<<0<<0<<0;
    }
    //zhu shi qu xiao
    return 0;
}
