#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p1,p2;
char l1,l2;
bool k1,k2;
bool pl(char c){
    if(c=='A') return 0;
    if(c=='B') return 0;
    if(c=='C') return 0;
    if(c=='D') return 1;
    if(c=='E') return 1;
}int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p1=s1[0]*10+s1[1]-480-48;
    p2=s2[0]*10+s2[1]-480-48;
    l1=s1[2];
    l2=s2[2];
    k1=pl(l1);
    k2=pl(l2);
    if(c1==c2){
        cout<<1;
        if(p1==p2){
            cout<<1;
            if(k1==k2){
                cout<<1;
                if(l1>l2) swap(l1,l2);
                if((l1=='A'&&l2=='B')||(l1=='B'&&l2=='C')||(l1=='D'&&l2=='E')){
                    cout<<1;
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
