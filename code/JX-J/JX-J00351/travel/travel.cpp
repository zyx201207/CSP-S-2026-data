#include<bits/stdc++.h>
using namespace std;
bool ist(char a,char b){
    bool posa=0,posb=0;
    if(a=='D'||a=='E')posa=1;
    if(b=='D'||b=='E')posb=1;
    if(posa==posb)return 1;
    return 0;
}
bool isc(char a,char b){
    if(abs(a-b)==1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //int n;
    int c1,c2,r1,r2;
    char c11,c12,c13,c21,c22,c23;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    c11=s1[0];
    c12=s1[1];
    c13=s1[2];
    c21=s2[0];
    c22=s2[1];
    c23=s2[2];
    r1=10*(int(c11)-48)+(int(c12));
    r2=10*(int(c21)-48)+(int(c22));
    if(c13=='F')c13='E';
    if(c23=='F')c23='E';
    if(c1==c2){
        cout<<1;
        if(r1==r2){
            cout<<1;
            if(ist(c13,c23)){
                cout<<1;
                if(isc(c13,c23)){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
