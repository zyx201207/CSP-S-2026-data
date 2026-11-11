#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cr,cx;
    string sr,sx;
    cin>>cr>>sr>>cx>>sx;
    int ar,br,ax,bx;
    int cnt=0;
    ar=sr[0]+sr[1];
    br=sr[2];
    ax=sx[0]+sx[1];
    bx=sx[2];
    if(cr==cx){
        cnt+=1000;
        if(ar==ax){
            cnt+=100;
            if((br=='C'&&bx=='D')||(br=='D'&&bx=='C'))cnt+=0;
            else{
                cnt+=10;
                if(abs(br-bx)==1)cnt++;
            }
        }
    }
    if(cnt==0)cout<<"0000";
    else cout<<cnt;
    return 0;
}
