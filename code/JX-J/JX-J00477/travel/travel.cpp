#include<bits/stdc++.h>
using namespace std;
char a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<0000;
    }else if(c1==c2){
        if(s1!=s2){
            cout<<1000;
        }else if(s1==s2-1||s1==s2+1){
            cout<<1111;
        }
    }
    return 0;

}
