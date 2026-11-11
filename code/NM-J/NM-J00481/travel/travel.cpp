#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int e=0,f=0,g=0,h=0;
    cin>>a>>b>>c>>d;
    e = int(a[0]-48)*10+a[1]-48;
    f = int(b[0]-48)*10+b[1]-48;
    g = int(c[0]-48)*10+c[1]-48;
    h = int(d[0]-48)*10+d[1]-48;
    if(e==g){
        cout<<1;
        if(f==h){
            cout<<1;
            if((b[2]=='A' && d[2]=='B') || (b[2]=='A' && d[2]=='C') || (b[2]=='B' && d[2]=='A') || (b[2]=='B' && d[2]=='C') || (b[2]=='C' && d[2]=='A') || (b[2]=='C' && d[2]=='B') || (b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D')){
                cout<<1;
                if((b[2]=='A' && d[2]=='C') || (b[2]=='C' && d[2]=='A')){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
