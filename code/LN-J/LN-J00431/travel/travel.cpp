#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a,b,c,d;
    a=b=c=d=false;
    int c1,c2;
    string s1,s2;
    int q,w;
    cin>>c1>>s1>>c2>>s2;
    q=(s1[0]-'0')*10+s1[1]-'0';
    w=(s2[0]-'0')*10+s2[1]-'0';
    if(c1==c2){
        a=true;
        if(q==w){
            b=true;
               if(s1[2]=='A'){
                    if(s2[2]=='B')c=d=true;
                    else if(s2[2]=='C') c=true;
               }else if(s1[2]=='B'){
                   if(s2[2]=='A' || s2[2]=='C')c=d=true;
               }else if(s1[2]=='C'){
                   if(s2[2]=='B') c=d=true;
                   else if(s2[2]=='A') c=true;
               }else if(s1[2]=='D'){
                   if(s2[2]=='F') c=d=true;
               }else if(s2[1]=='F'){
                   if(s2[2]=='D') c=d=true;
               }
            }
        }
    cout<<a<<b<<c<<d;
    return 0;
}
