#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int ans[4]={};
    if(c1==c2) ans[0]=1;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) ans[1]=1;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]<='C'&&s2[2]<='C'){
        ans[2]=1;
        a4=1;
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]>='D'&&s2[2]>='D'){
      ans[2]=1;
        a4=2;
    }
    if(a4==2) ans[3]=1;
    if(a4==1&&s1[2]>'A'&&s2[2]>'A') ans[3]=1;
    if(a4==1&&s1[2]<'C'&&s2[2]<'C') ans[3]=1;
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3];
    return 0;
}
