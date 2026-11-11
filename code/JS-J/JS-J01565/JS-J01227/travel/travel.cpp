#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="0000";
    if(c1==c2){
        ans[0]='1';
        int num1=stoi(s1.substr(0,2)),num2=stoi(s2.substr(0,2));
        bool f1=(num1==num2);
        bool f2=(s1[2]==s2[2]);
        bool f3=(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D');
        if(f1){
            ans[1]='1';
            if(f3)
                ans[2]='1';
        }
        if(( f1&&abs(s1[2]-s2[2])==1 || f2&&abs(num1-num2)==1 )&&f3)
            ans[3]='1';
    }
    cout<<ans<<'\n';
    return 0;
}
