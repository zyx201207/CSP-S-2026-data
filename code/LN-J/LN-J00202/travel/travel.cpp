#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=1e5+5;
int c1,c2;
string s1,s2;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            char a=s1[2],b=s2[2];
            if((a=='D'&&b=='F')||(a=='F'&&b=='D'))cout<<"11";
            else if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
                cout<<1;
                if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='B'&&b=='C')||(a=='C'&&b=='B'))cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
