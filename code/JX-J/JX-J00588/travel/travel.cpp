#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    int x=0,xx=0;
    int l=c.size();
    int ll=s.size();
    int lc=cc.size();
    int ls=ss.size();
    for(int i=0;i<l;i++){
        if(c[i]>='0'&&c[i]<='9'){
            x=x*10+(c[i]-'0');
        }
    }
    for(int i=0;i<lc;i++){
        if(cc[i]>='0'&&cc[i]<='9'){
            xx=xx*10+(cc[i]-'0');
        }
    }
    if(x==xx){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int p=0,pp=0;
    for(int i=0;i<ll;i++){
        if(s[i]>='0'&&s[i]<='9'){
            p=p*10+(s[i]-'0');
        }
    }
    for(int i=0;i<ls;i++){
        if(ss[i]>='0'&&ss[i]<='9'){
            pp=pp*10+(ss[i]-'0');
        }
    }
    if(p==pp){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    char a,b;
    for(int i=0;i<ll;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            a=s[i];
        }
    }
    for(int i=0;i<ls;i++){
        if(ss[i]>='A'&&ss[i]<='Z'){
            b=ss[i];
        }
    }
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
        cout<<1;
    }else if((a=='D'||a=='F')&&(b=='D'||b=='F')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(a-b)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
