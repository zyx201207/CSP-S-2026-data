#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs;
int k,l,p;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>as>>bc>>bs;
    p=(ac==bc);
    cout<<p;
    if(p==1){
        l=(as[0]==bs[0]&&as[1]==bs[1]);
    }
    cout<<l;
    if(l==1){
        if(as[2]-'A'<=2&&bs[2]-'A'<=2 || as[2]-'A'>2&&bs[2]-'A'>2){
            k=1;
        }
    }

    cout<<k;
    if(k==1){
        cout<<((as[2]-'A')-(bs[2]-'A')==1||(as[2]-'A')-(bs[2]-'A')==-1);
    }else cout<<0;
    return 0;
}
