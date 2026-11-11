#include <bits/stdc++.h>
using namespace std;
int a[5],b[5];
bool is(int a,int b){
    if(a==int('D') && b==int('F')){
        return true;
    }
    else if(a==int('F') && b==int('D')){
        return true;
    }
    else if(a==int('A') && (b==int('B') || b==int('C'))){
        return true;
    }
    else if(a==int ('B') && (b==int('A') ||b==int('C'))){
        return true;
    }
    else if(a==int('C') && (b==int('A') || b==int('B'))){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }

    for(int i=0;i<=2;i++){
        a[i]=int(s1[i]);
        b[i]=int(s2[i]);

    }

    bool f=1;
    for(int i=0;i<=1;i++){
        if(a[i]!=b[i]) f=0;
    }
    if((c1==c2) && f==1) cout<<1;
    else cout<<0;

    for(int i=2;i<=2;i++){
        if((c1==c2) && f==1 && ((a[i]<=int('C') && b[i]<=int('C')) || (a[i]>=int('D') && b[i]>=int('D')))){
            cout<<1;
        }
        else {
            cout<<0;
        }
    }

    for(int i=2;i<=2;i++){
        if((c1==c2) && f==1 && is(a[i],b[i])){
            cout<<1;
        }
        else cout<<0;
    }
    return 0;
}
