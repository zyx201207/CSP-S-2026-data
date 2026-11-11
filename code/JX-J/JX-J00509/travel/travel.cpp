#include<bits/stdc++.h>
#define PBB pair<bool,bool>
using namespace std;
string c1,s1,c2,s2;
bool flag;
PBB ans;
void check(string a,string b){
    if('A'<=a[2]&&a[2]<='C'&&'A'<=b[2]&&b[2]<='C'||'D'<=a[2]&&a[2]<='F'&&'D'<=b[2]&&b[2]<='F') ans.first=true;
    else ans.first=false;
    if(!flag) ans.first=false;
    if(!ans.first) ans.second=false;
    else if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&(b[2]=='A'||b[2]=='C')||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D') ans.second=true;
    else ans.second=false;
    if(!flag) ans.second=false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    flag=(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
    check(s1,s2);
    cout<<(c1==c2)<<flag<<ans.first<<ans.second;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
