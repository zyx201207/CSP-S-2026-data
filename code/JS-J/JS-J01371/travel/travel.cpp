#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1.substr(0,2)!=s2.substr(0,2)){
        cout<<1000;
        return 0;
    }
    char a1=s1[2],a2=s2[2];
    if((a1<'D')==(a2<'D')){
        if(a1*a2==int('F')*(int)'D' || a1+a2=='A'+'B' || a1*a2==int('B')*(int)'C')
            cout<<1111;
        else cout<<1110;
    }
    else{
        cout<<1100;
    }
}
