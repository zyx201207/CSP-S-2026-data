#include<bits/stdc++.h>
using namespace std;
string l1,a1,l2,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>l1>>a1>>l2>>a2;
    //cout<<a1[1]<<" "<<a1[2]<<"\n";
    //----------------------
    if(l1==l2) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    //----------------------
    if(a1[0]==a2[0]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    //----------------------
    if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(a2[2]=='D'||a2[2]=='E')||(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(a1[2]=='D'||a1[2]=='E')){
        cout<<"00";
        return 0;
    }
    else cout<<"1";
    //----------------------
    if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='A')||(a1[2]=='C'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='C')||(a1[2]=='E'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='E')){
        cout<<"1";
    }
    else cout<<"0";
    return 0;
}
// 15 09D 15 09B
