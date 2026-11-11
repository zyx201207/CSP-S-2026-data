#include<bits/stdc++.h>
//#define int long long
using namespace std;
char ch1[110],sh1[110],ch2[110],sh2[110];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ch1+1>>sh1+1>>ch2+1>>sh2+1;
    if(ch1[1]==ch2[1]&&ch1[2]==ch2[2]){
        cout<<1;
        if(sh1[1]==sh2[1]&&sh1[2]==sh2[2]){
            cout<<1;
            if((sh1[3]=='A'||sh1[3]=='B'||sh1[3]=='C')&&(sh2[3]=='A'||sh2[3]=='B'||sh2[3]=='C')){
                cout<<1;
                if(abs(sh1[3]-sh2[3])==1) cout<<1;
                else cout<<0;
            }
            else if((sh1[3]=='D'||sh1[3]=='E')&&(sh2[3]=='D'||sh2[3]=='E')){
                cout<<1;
                if(abs(sh1[3]-sh2[3])==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
