#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int ans[10]={0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c[0]==cc[0]&&c[1]==cc[1]){
        ans[1]=1;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]&&ans[1]==1){
        ans[2]=1;
    }
    if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')&&ans[2]==1){
        ans[3]=1;
    }
    if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F')&&ans[2]==1){
        ans[3]=1;
    }
    if((s[2]-ss[2]==1||ss[2]-s[2]==1)&&ans[3]==1){
        ans[4]=1;
    }
    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
    return 0;
}
