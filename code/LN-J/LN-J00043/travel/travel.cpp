#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
int main(){
    init();
    //freopen("travel5.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string s,s2,s3,s4;
    cin>>s>>s2>>s3>>s4;
    if(s==s3){
        cout<<1;
        if(s2[0]==s4[0]&&s2[1]==s4[1]) {
            cout<<1;
            char ch=s2[2],ch2=s4[2];
            if(ch>ch2) swap(ch,ch2);
            if(ch<='C'&&ch2>='D') cout<<"00\n";
            else{
                cout<<1;
                if(ch2-ch==1) cout<<1<<"\n";
                else cout<<0<<"\n";
            }
        }
        else cout<<"000\n";
    }
    else cout<<"0000\n";
    return 0;
}
