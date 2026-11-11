#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string ca,cb;
    string sa,sb;
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb){
        cout<<1;
        if(sa[0]+sa[1]==sb[0]+sb[1]){
            cout<<1;
            if(abs(sa[2]-sb[2])<=2 && !(sa[2]=='C' && sb[2]=='D') && !(sa[2]=='D' && sb[2]=='C')){
                cout<<1;
                if(abs(sa[2]-sb[2])==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }


    return 0;
}
