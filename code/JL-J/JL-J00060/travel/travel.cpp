#include<bits/stdc++.h>
using namespace std;
bool k=1,k2=1;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            cout<<0<<0<<0<<0;
            return 0;
        }
    }
    cout<<1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<0<<0<<0;
            return 0;
        }
    }
    cout<<1;
    if(s1[2]>'C'){
        k=0;
    }
    if(s2[2]>'C'){
        k2=0;
    }
    if(k!=k2){
        cout<<0<<0;
        return 0;
    }
    cout<<1;
    if(s1[2]+1==s2[2]+1-1||s1[2]-1==s2[2]+1-1){
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
