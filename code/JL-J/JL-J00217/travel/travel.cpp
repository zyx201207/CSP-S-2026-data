#include<bits/stdc++.h>
using namespace std;
//#define int long long
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1){
        cout<<1;
        if(s2[0]==c2[0] and s2[1]==c2[1]){
            cout<<1;
            if((s2[2]>='A' and s2[2]<='C') and (c2[2]>='A' and c2[2]<='C')
               or (s2[2]=='D' or s2[2]=='F') and (c2[2]=='D' and c2[2]=='F')){
               cout<<1;
               int a=abs(int(s2[2]-c2[2]));
                if(a==1) cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";


    return 0;
}
