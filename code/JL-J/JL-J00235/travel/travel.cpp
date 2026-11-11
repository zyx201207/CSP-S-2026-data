#include<bits/stdc++.h>
using namespace std;
string r,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    long long lenr=r.length();
    long long lenx=x.length();
    string seatr;
    string seatx;
    string coder;
    string codex;
    cin>>coder>>seatr>>codex>>seatx;
    if(coder==codex) cout<<1; else cout<<0;
    if(coder==codex&&seatr[0]==seatx[0]&&seatr[1]==seatx[1]) cout<<1; else cout<<0;
    if(coder==codex&&seatr[0]==seatx[0]&&seatr[1]==seatx[1]&&seatr[2]<='C'&&seatx[2]<='C'||seatx[2]>='D'&&seatr[2]>='D') cout<<1; else cout<<0;
    if(coder==codex&&seatr[0]==seatx[0]&&seatr[1]==seatx[1]&&seatr[2]<='C'&&seatx[2]<='C'||seatx[2]>='D'&&seatr[2]>='D'&&seatr[2]==seatx[2]+1&&seatr[2]<='C'&&seatx[2]<='C'||seatr[2]==seatx[2]-1&&seatx[2]>='D'&&seatr[2]>='D') cout<<1; else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
