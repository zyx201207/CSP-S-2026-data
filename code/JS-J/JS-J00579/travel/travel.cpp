#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    bool f1=0,f2=0,f3=0,f4=0;
    int d1,d2,z1,z2;
    char b1,b2;
    cin>>c1>>s1>>c2>>s2;
    d1=(c1[0]-'0')*10+(c1[1]-'0'),d2=(c2[0]-'0')*10+(c2[1]-'0'),z1=(s1[0]-'0')*10+(s1[1]-'0'),z2=(s2[0]-'0')*10+(s2[1]-'0'),b1=s1[2],b2=s2[2];
    if(d1==d2)
        f1=1;
    if(z1==z2)
        f2=1;
    if((b1<'D'&&b2<'D')||(b1>='D'&&b2>='D'))
        f3=1;
    if(abs(b1-b2)==1)
        f4=1;
    if(f1){
        cout<<"1";
        if(f2){
            cout<<"1";
            if(f3){
                cout<<"1";
                if(f4){
                    cout<<"1";
                }else{
                    cout<<"0";
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
