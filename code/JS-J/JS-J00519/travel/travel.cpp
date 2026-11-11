#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
string ans="0000";
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        ans[0]='1';
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            ans[1]='1';
            if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')){
                ans[2]='1';
                if(abs(s2[2]-s4[2])==1){
                    ans[3]='1';
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//g++ travel.cpp -o travel -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576 && ulimit -s 1048576 && time ./travel