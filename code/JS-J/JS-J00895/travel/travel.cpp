#include<bits/stdc++.h>
using namespace std;
int c,C,t=0,l=0,o=0;
string s,S;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>C>>S;
    if(c==C){
    cout<<1;
     o=1;
    }
    else cout<<0;
    for(int i=0;i<2;i++){
        if(s[i]!=S[i]){
            cout<<0;
            t=1;
        }
    }if(t==0){
        if(o==1)cout<<1;
        else cout<<0;
    }

    if(o==1&&t==0&&((s[2]>='D'&&S[2]>='D')||(s[2]<'D'&&S[2]<'D'))){
       l=1;
       cout<<1;
       }else cout<<0;
    if(o==1&&t==0&&l==1&&(abs(int(s[2])-int(S[2]))==1)||((s[2]=='D'&&S[2]=='F')||(s[2]=='F'&&S[2]=='D')))cout<<1;
    else cout<<0;
    return 0;
}
