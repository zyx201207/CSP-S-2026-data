#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c1,c2;
string s1,s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        int a=s1[0]*100+s1[1]*10;
        int b=s2[0]*100+s2[1]*10;
        if(a==b){
            cout<<1;
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
                cout<<1;
                if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
                cout<<11;
            }
            else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }
    else cout<<"0000";

    return 0;
}
