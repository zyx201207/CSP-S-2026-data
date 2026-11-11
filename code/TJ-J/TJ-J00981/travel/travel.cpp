#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[10];
map<char,int> ton;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char R1,R2;
    char X1,X2;
    cin>>R1>>R2;
    string s,s2;
    cin>>s;
    cin>>X1>>X2;
    cin>>s2;
    ton['A']=1,ton['B']=1,ton['C']=1,ton['D']=2,ton['F']=2;
    if (R1==X1 && R2==X2) ans[1]=1;
    else{
        cout<<"0000";
        return 0;
    }
    if (s[0]==s2[0] && s[1]==s2[1]){
        ans[2]=1;
    }
    else{
        cout<<"1000";
        return 0;
    }
    if (ton[s[2]]==ton[s2[2]]){
        ans[3]=1;
    }
    else{
        cout<<"1100";
        return 0;
    }
    if (ton[s[2]]==2) ans[4]=1;
    if (s[2]=='B' || s2[2]=='B') ans[4]=1;
    if (!ans[4]){
        cout<<"1110";
        return 0;
    }
    else{
        cout<<"1111";
        return 0;
    }
    return 0;
}
