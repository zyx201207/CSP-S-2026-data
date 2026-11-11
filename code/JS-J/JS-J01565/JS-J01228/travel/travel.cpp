#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int c,s;
    c=int(c1[0]-48)*10+int(c1[1]-48);
    s=int(c2[0]-48)*10+int(c2[1]-48);
    if(c==s){
        cout<<1;
        c=int(s1[0]-48)*10+int(s1[1]-48);
        s=int(s2[0]-48)*10+int(s2[1]-48);
        if(c==s){
            cout<<1;
            char a=s1[2],b=s2[2];
            if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
                cout<<1;
                if(abs(a-b)==1&&!(a=='C'&&b=='D')&&!(a=='D'&&b=='C')){
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
    }else{
        cout<<0<<0<<0<<0;
    }

    return 0;
}
