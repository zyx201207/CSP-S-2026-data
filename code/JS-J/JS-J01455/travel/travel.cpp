#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+="1";
            char m=s1[2];
            char d=s2[2];
            if((m=='D'&&d=='F')||(m=='F'&&d=='D')||(m=='A'&&d=='B')||(m=='B'&&d=='A')||(m=='C'&&d=='B')||(m=='B'&&d=='C')||(m=='A'&&d=='C')||(m=='C'&&d=='A')){
                    ans+="1";
                if((m=='D'&&d=='F')||(m=='F'&&d=='D')||(m=='A'&&d=='B')||(m=='B'&&d=='A')||(m=='C'&&d=='B')||(m=='B'&&d=='C')){
                    ans+="1";
                }
                else ans+="0";
            }
            else ans+="00";
        }
        else ans+="000";
    }
    else ans="0000";
    cout<<ans;
    return 0;
}
