#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c,s,cc,ss,ca,cb;
char cd,cf;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    for(int i=0;i<=1;i++){
        ca+=s[i];
        cb+=ss[i];
    }
    cd=s[2];
    cf=ss[2];
    if(c==cc){
        cout<<1;
        if(ca==cb){
            cout<<1;
            if(cd>='D' && cf>='D' || cf<'D' && cf<'D') {
                cout<<1;
                if(abs(cd-cf)<=1 || cd+cf=='D'+'F') cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
