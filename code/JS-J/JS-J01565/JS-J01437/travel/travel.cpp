#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;

    if(c1==s1)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    int a=(c2[0]-'0')*10+(c2[1]-'0');
    int b=(s2[0]-'0')*10+(s2[1]-'0');
    if(a==b)cout<<1;
    else cout<<0;

    char c=c2[2];
    char s=s2[2];
    if(a==b&&((c=='A' && s=='B')||(c=='B' && s=='A')||(c=='C' && s=='A')||(c=='A' && s=='C')||(c=='B' && s=='C')||(c=='C' && s=='B'))){
        cout<<1;
    }else if(a==b&&((c=='D' && s=='F')||(c=='F' && s=='D'))){
        cout<<1;
    }else{
        cout<<0;
    }

    if(abs(a-b)==1 && c==s){
        cout<<1;
    }else if((c=='D'&&s=='C')||(c=='C'&&s=='D')){
        cout<<0;
    }else if(abs(int(c)-int(s))==1&&a==b){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
