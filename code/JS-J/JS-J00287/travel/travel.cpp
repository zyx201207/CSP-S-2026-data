#include<bits/stdc++.h>
using namespace std;
string ac,az,bc,bz;
int chehao(string s){
    int hao=0;
    for(int i=0;i<=1;i++){
        hao+=(s[i]-'0');
        hao*=10;
    }
    return hao;
}


int main(){
    ios::sync_with_stdio(0);

    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>az>>bc>>bz;
    bool f=true;
    if(ac==bc)cout<<1;
    else {
        f=false;
        cout<<0;
    }//first

    if(f&&(chehao(az)==chehao(bz)))cout<<1;
    else {
        f=false;
        cout<<0;
    }//second

    if(f&&((az[2]>='A'&&az[2]<='C'&&bz[2]>='A'&&bz[2]<='C')||(az[2]>='D'&&az[2]<='F'&&bz[2]>='D'&&bz[2]<='F')))cout<<1;
    else {
        f=false;
        cout<<0;
    }//third

    if(f&&(az[2]-bz[2]==-1||az[2]-bz[2]==1))cout<<1;
    else cout<<0;

    return 0;
}
