#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char ans[10];
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c==cc)
        ans[1]='1';
    else{
        cout<<"0000";
        return 0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]){
        ans[2]='1';
    }
    else{
        cout<<"1000";
        return 0;
    }
    if((('A'<=s[2]&&s[2]<='C')&&('A'<=ss[2]&&ss[2]<='C'))||(('D'==s[2]||s[2]=='F')&&('D'==ss[2]||ss[2]=='F'))){
        ans[3]='1';
    }
    else{
        cout<<"1100";
        return 0;
    }
    if((('A'<=s[2]&&s[2]<='C')&&(abs(ss[2]-s[2])==1))||(('D'==s[2]||s[2]=='F'))){
        ans[4]='1';
    }
    else{
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
