#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+="1";
            if(s1>s2)swap(s1,s2);
            if(s1[2]+s2[2]=='D'+'F'||s1[2]<='C'&&s2[2]<='C'){
                ans+="1";
                if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'){
                    ans+="1";
                }
            }
        }
    }
    while(ans.size()<4)ans+="0";
    cout<<ans<<'\n';
    return 0;
}