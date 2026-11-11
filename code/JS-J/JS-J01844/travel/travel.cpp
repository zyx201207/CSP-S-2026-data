#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="0000";
    if(c1==c2){
        ans[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]) {
            ans[1]='1';
            bool tf1=false,tf2=false;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') tf1=true;
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') tf2=true;
            if((tf1&&tf2)||(!tf1&&!tf2)){
                ans[2]='1';
                if(abs(s1[2]-s2[2])==1) ans[3]='1';
            }
        }
    }
    cout<<ans;
    return 0;
}
