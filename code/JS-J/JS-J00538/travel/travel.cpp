#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
bool a=0,b=0,c=0,d=0;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) a=1;
    if(a){
        if(s1[0]!=s2[0]||s1[1]!=s2[1]) b=0;
        else b=1;
        if(b){
            if(s1[2]=='A'){
                if(s2[2]=='B'||s2[2]=='C') c=1;
            }
            if(s1[2]=='B'){
                if(s2[2]=='A'||s2[2]=='C') c=1;
            }
            if(s1[2]=='C'){
                if(s2[2]=='B'||s2[2]=='A') c=1;
            }
            if(s1[2]=='D'){
                if(s2[2]=='F') c=1;
            }
            if(s1[2]=='F'){
                if(s2[2]=='D') c=1;
            }
        }
        if(c){
            if(s1[2]=='A'){
            if(s2[2]=='B') d=1;
            }
            else if(s1[2]=='B'){
                if(s2[2]=='A'||s2[2]=='C') d=1;
                }
                else if(s1[2]=='C'){
                    if(s2[2]=='B') d=1;
                }
                else if(s1[2]=='D'){
                    if(s2[2]=='F') d=1;
                }
                else if(s1[2]=='F'){
                    if(s2[2]=='D') d=1;
                }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
