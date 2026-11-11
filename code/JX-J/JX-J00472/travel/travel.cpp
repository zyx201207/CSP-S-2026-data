#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,sa,cc,sc;
    cin>>ca>>sa>>cc>>sc;
    if(ca==cc){
        if(sa[0]==sc[0]&&sa[1]==sc[1]){
            if((sa[2]<='C'&&sc[2]<='C')||(sa[2]>='D'&&sc[2]>='D')){
                if((sa[2]-sc[2]==1)||(sc[2]-sa[2]==1)){
                    cout<<'1111';
                }else cout<<'1110';
            }else cout<<'1100';
        }else cout<<'1000';
    }else cout<<'0000';
    return 0;
}
