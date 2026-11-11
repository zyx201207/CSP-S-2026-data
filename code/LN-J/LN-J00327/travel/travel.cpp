#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d,ic1,ic2;
    char c1,c2;
    cin>>a>>b>>c1>>c>>d>>c2;
    if(a==c)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(b==d)cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if(c1=='A' or c1=='B' or c1=='C')ic1=1;
    else ic1=2;
    if(c2=='A' or c2=='B' or c2=='C')ic2=1;
    else ic2=2;
    if(ic1==ic2){
        cout<<1;
        ic1=c1-'A';
        ic2=c2-'A';
        if(c2=='F')ic2=4;
        if(c1=='F')ic1=4;
        if(ic1-ic2==1 or ic2-ic1==1)cout<<1;
        else cout<<0;
    }else cout<<"00";
    return 0;
}
