#include<bits/stdc++.h>
#define ll long long
#define atn 222222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
bool sd(char c){
    if(c=='A'||c=='B'||c=='C')return 0;
    else return 1;
}
bool ck(char a,char b){
    if(a=='A'&&b=='B')return 1;
    if(a=='B'&&b=='C')return 1;
    if(a=='D'&&b=='F')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(sd(s1[2])==sd(s2[2])){
                cout<<"1";
                if(ck(s1[2],s2[2])){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";


    return 0;
}
