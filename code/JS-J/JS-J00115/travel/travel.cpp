#include<bits/stdc++.h>
using namespace std;
char ca[3],sa[4],cb[3],sb[4];
int ct,sum;
int main(){
    for(int i=0;i<2;i++) cin>>ca[i];
    for(int i=0;i<3;i++) cin>>sa[i];
    for(int i=0;i<2;i++) cin>>cb[i];
    for(int i=0;i<3;i++) cin>>sb[i];
    for(int i=0;i<2;i++){
        if(ca[i]==cb[i]) ct++;
        if(sa[i]==sb[i]) sum++;
    }
    if(ct==2) cout<<"1";
    else if(ct!=2){
        cout<<"0000";
        return 0;
        }
    if(sum==2) cout<<"1";
    else {
        cout<<"000";
        return 0;
        }
    if((sa[2]<'D'&&sb[2]<'D')||(sa[2]>'C'&&sb[2]>'C')) cout<<"1";
    else {
        cout<<"00";
        return 0;
        }
        if(sa[2]+1==sb[2]||sa[2]-1==sb[2]) cout<<"1";
        else cout<<"0";
    return 0;
}

