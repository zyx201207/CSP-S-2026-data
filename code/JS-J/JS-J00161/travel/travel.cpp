# include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string c1,s1,c2,s2,ans="";
    cin>>c1>>s1>>c2>>s2;
    bool s11=false,s22=false,s111=false,s222=false;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s11=true;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s22=true;
    if(s1[2]=='D'||s1[2]=='E') s111=true;
    if(s2[2]=='D'||s2[2]=='E') s222=true;
    if(c1==c2){
        ans+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+="1";
            if((s11&&s22)||(s111&&s222)){
                ans+="1";
                if(abs(int(s1[2])-int(s2[2]))==1) ans+="1";
                else ans+="0";
            }
            else ans+="00";
        }
        else ans+="000";
    }
    else ans+="0000";
    cout<<ans;
}
