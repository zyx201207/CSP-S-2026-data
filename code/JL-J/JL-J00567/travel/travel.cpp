#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string a,b,c,d;
void pai(string a1,string b1){
    for(int i=0;i<=1;i++){
        if(a1[i]!=b1[i]){
            cout<<"000";
            return ;
        }
    }
    cout<<"1";
    if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')){
        cout<<"1";
        if(a1[2]-b1[2]==1||b1[2]-a1[2]==1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else if((a1[2]=='D'||a1[2]=='F')&&(b1[2]=='D'||b1[2]=='F')){
        cout<<"11";
    }else{
        cout<<"00";
    }
    return ;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        pai(b,d);
    }else{
        cout<<"0000";
    }

    return 0;
}
