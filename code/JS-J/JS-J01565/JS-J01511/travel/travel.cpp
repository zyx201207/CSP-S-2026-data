#include <bits/stdc++.h>
using namespace std;
int cr,cx;
char s1r,s2r,s1x,s2x,s3x,s3r;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>s1r>>s2r>>s3r>>cx>>s1x>>s2x>>s3x;
    if(cx==cr)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1r==s1x&&s2r==s2x)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int ra=0,xa=0;
    if(s3r=='A'||s3r=='B'||s3r=='C'){
        ra=1;
    }
    if(s3x=='A'||s3x=='B'||s3x=='C'){
        xa=1;
    }
    if(ra==xa){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((s3r=='A'&s3x=='B')||(s3r=='B'&s3x=='C')||(s3r=='D'&s3x=='F'))cout<<1;
    else{
        cout<<0;
    }
    return 0;
}
