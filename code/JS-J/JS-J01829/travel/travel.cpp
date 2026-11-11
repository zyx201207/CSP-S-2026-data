#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
string s1,s2,s3,s4,ans;
signed main(){
    //travel
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>s1>>s2>>s3>>s4;
ans+=(s1==s3?"1":"0000");
if(ans.size()>1){
    cout<<ans;
    return 0;
}
ans+=(s2[0]==s4[0]&&s2[1]==s4[1]?"1":"000");
if(ans.size()>3){
    cout<<ans;
    return 0;
}
ans+=(s2[2]=='A'&&s4[2]=='B'||
      s2[2]=='C'&&s4[2]=='A'||
      s2[2]=='A'&&s4[2]=='C'||
      s2[2]=='C'&&s4[2]=='B'||
      s2[2]=='B'&&s4[2]=='A'||
      s2[2]=='B'&&s4[2]=='C'||
      s2[2]=='D'&&s4[2]=='F'||
      s2[2]=='F'&&s4[2]=='D'?"1":"00");
if(ans.size()>3){
    cout<<ans;
    return 0;
}
ans+=(s2[2]=='A'&&s4[2]=='B'||
      s2[2]=='B'&&s4[2]=='A'||
      s2[2]=='B'&&s4[2]=='C'||
      s2[2]=='C'&&s4[2]=='B'||
      s2[2]=='D'&&s4[2]=='F'||
      s2[2]=='F'&&s4[2]=='D'?'1':'0');
      cout<<ans;
}
