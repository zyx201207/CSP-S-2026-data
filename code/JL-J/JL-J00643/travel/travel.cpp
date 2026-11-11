#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    int a,b;
    string s,q,c="",d="";
    cin>>a>>s>>b>>q;
    if(a==b) cout<<'1';
    else{
        cout<<'0'<<'0'<<'0'<<'0';
        return 0;
    }
    c=c+s[0]+s[1];
    d=d+q[0]+q[1];
    int w=int(s[2])-int(q[2]);
    if(w<0) w=w-2*w;

    if(c==d){
        cout<<'1';
    }
    else{
        cout<<'0'<<'0'<<'0';
        return 0;
    }

    if(w==1&&s[2]!='D'&&q[2]!='D' || w==2&&(s[2]!='B'&&q[2]!='B')) cout<<'1';
    else cout<<'0';



    if(w==1&&s[2]!='D'&&q[2]!='D' || w==2&&(s[2]=='F'||q[2]=='F')) cout<<'1';
    else cout<<'0';



    return 0;
}
