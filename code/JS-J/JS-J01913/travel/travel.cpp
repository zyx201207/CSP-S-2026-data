#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int x1=int(s1[2]-'A')+1;
    int x2=int(s2[2]-'A')+1;
    if(c1==c2){
        ans+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+="1";
            if(x1<=3&&x2<=3||x1>3&&x2>3){
                ans+="1";

                int x2=int(s2[2]-'A'+1);
                if((x1<=3&&x2<=3&&(x1+1==x2||x1-1==x2))||(x1>3&&x2>3)){
                    ans+="1";
                }
                else ans+="0";

            }
            else ans+="00";
        }
        else ans+="000";
    }
    else ans+="0000";
    cout<<ans;
    return 0;
}
