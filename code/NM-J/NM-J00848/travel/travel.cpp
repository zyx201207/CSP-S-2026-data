#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
bool f(char x){
    return (x=='A'||x=='B'||x=='C');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans[1]='1';
            if(f(s1[2])==f(s2[2])){
                ans[2]='1';
                if(!f(s1[2])||s1[2]=='B'||s2[2]=='B'){
                    ans[3]='1';
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
