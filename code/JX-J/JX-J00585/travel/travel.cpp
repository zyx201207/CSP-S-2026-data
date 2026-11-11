#include<bits/stdc++.h>
using namespace std;
string r1,x1;
int r,x;
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r1>>x>>x1;
    if(r==x){
        a=1;
        if(r1[0]==x1[0]&&r1[1]==x1[1]){
            b=1;
            if((r1[2]=='A'||r1[2]=='B'||r1[2]=='C')&&(x1[2]=='C'||x1[2]=='A'||x1[2]=='B')){
                c=1;
            }
            else if((r1[2]=='D'||r1[2]=='F')&&(x1[2]=='D'||x1[2]=='F')){
                c=1;
            }
        }
    }
    if(a==1&&b==1&&c==1){
        if(max(x1[2],r1[2])-min(x1[2],r1[2])==1){
            d=1;
        }
    }
    if(x1[2]=='C'&&r1[2]=='D') d=0;
    else if(x1[2]=='D'&&r1[2]=='C') d=0;
    cout<<a<<b<<c<<d;
    return 0;
}
//
