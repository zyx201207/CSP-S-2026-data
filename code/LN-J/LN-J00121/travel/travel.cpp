#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int si1=0,si2=0;
    int l=0;
    while(s1[l]<='9'){
        si1=si1*10+s1[l]-'0';
        l++;
    }
    char z1=s1[l];
    l=0;
    while(s2[l]<='9'){
        si2=si2*10+s2[l]-'0';
        l++;
    }
    char z2=s2[l];
    if(c1==c2){
        cout<<1;
        if(si1==si2){
            cout<<1;
            if(!(((z1-'A')<=2)^((z2-'A')<=2))){
                cout<<1;
                if(z1=='F')z1='E';
                if(z2=='F')z2='E';
                if((z2-z1)*(z2-z1)==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
}