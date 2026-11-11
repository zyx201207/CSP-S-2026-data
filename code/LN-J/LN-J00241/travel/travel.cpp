#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a1,a2,b1,b2;
    a1=(c1[0]-'0')*10+(c1[1]-'0');
    b1=(s1[0]-'0')*10+(s1[1]-'0');
    a2=(c2[0]-'0')*10+(c2[1]-'0');
    b2=(s2[0]-'0')*10+(s2[1]-'0');
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')){
                cout<<1;
                if(abs(s1[2]-s2[2])==1 || (s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F')){
                    cout<<1;
                }else{
                    cout<<0;
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
    return 0;
}
