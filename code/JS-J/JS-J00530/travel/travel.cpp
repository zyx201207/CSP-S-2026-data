#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
int t1,t2,t3,t4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        t1=1;
        string a,b;
        a+=s1[0]+s1[1];
        b+=s2[0]+s2[1];
        if(s1[0]==s2[0]&&s2[1]==s1[1]){
            t2=1;
            char c=s1[2];
            char d=s2[2];
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C') && (s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F') && (s2[2]=='D'||s2[2]=='F'))){
                t3=1;
                if( (s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s2[2]=='D')) t4=1;
                else t4=0;
            }
            else t3=0;
        }
        else t2=0;
    }
    else t1=0;
    cout<<t1<<t2<<t3<<t4;
    return 0;
}
