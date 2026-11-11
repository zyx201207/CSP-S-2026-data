#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int x=(s1[0]-'0')*10+s1[1]-'0';
    int y=(s2[0]-'0')*10+s2[1]-'0';
    if(c1==c2){
            ans[0]='1';
        if(x==y){
            ans[1]='1';
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
                ans[2]='1';
                if(abs(s1[2]-s2[2])==1||(s1[2]>='D')){
                    ans[3]='1';
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
