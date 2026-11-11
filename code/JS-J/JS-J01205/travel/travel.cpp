#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        char a1=s1[2];
        char a2=s2[2];
        if((a1<='C'&&a2<='C')||(a1>'C'&&a2>'C')){
            cout<<1;
            int a=a1-'0';
            int b=a2-'0';
            if(abs(a-b)==1){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0<<0;
        }
    }else{
        cout<<0<<0<<0;
    }

    return 0;

}
