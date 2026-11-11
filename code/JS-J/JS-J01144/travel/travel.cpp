#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;
bool f=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    if(ca[0]==cb[0]&&ca[1]==cb[1]) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(f==1&&sa[0]==sb[0]&&sa[1]==sb[1]) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(f==1&&sa[2]>='A'&&sa[2]<='C'&&sb[2]>='A'&&sb[2]<='C') cout<<1;
    else if(f==1&&sa[2]=='D'&&sb[2]=='F'||f==1&&sa[2]=='F'&&sb[2]=='D') cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(f==1&(int(sa[2])-int(sb[2])==1)&&sa[2]!='D'||f==1&&(int(sb[2])-int(sa[2])==1)&&sb[2]!='D') cout<<1;
    else if(f==1&&sa[2]=='D'&&sb[2]=='F'||f==1&&sa[2]=='F'&&sb[2]=='D') cout<<1;
    else cout<<0;
    return 0;
}
