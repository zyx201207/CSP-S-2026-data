#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string ss,cc;
        ss=s1;cc=s2;
        ss[2]='0';
        cc[2]='0';
        if(ss==cc){
            cout<<1;
            char a=s1[2];
            char b=s2[2];
            if((a>='A'&&a<='C')&&(b>='A'&&b<='C')){
                cout<<1;
                if(abs(a-b)==1){
                    cout<<1<<'\n';
                }else{
                    cout<<0<<'\n';
                }
            }else if((a>='D'&&a<='F')&&(b>='E'&&b<='F')){
                cout<<1<<1<<'\n';
            }else{
                cout<<"00"<<'\n';
            }
        }else{
            cout<<"000"<<'\n';
        }
    }else{
        cout<<"0000"<<'\n';
    }
    return 0;
}
