#include<bits/stdc++.h>
using namespace std;
const int N=0x3f3f3f3f;
#define ll long long
string ca,sa,cb,sb;
string s;
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    if(ca[0]!=cb[0] || ca[1]!=cb[1]){
        cout<<"0000";
        return 0;
    }
    if(sa[0]!=sb[0] || sa[1]!=sb[1]){
        cout<<"1000";
        return 0;
    }
    if((sa[2]-'0')>sb[2]-'0') swap(sa[2],sb[2]);
    if(sa[2]=='D') cout<<"1111";
    else{
        if(((sb[2]-'0')-(sa[2]-'0'))>2){
            cout<<"1100";
            return 0;
        }
        else{
            if(sa[2]=='C'){
                cout<<"1100";
                return 0;
            }
        }
        if((sb[2]-'0')-(sa[2]-'0')>1){
                cout<<"1110";
                return 0;
        }
        cout<<"1111";
    }
    return 0;
}