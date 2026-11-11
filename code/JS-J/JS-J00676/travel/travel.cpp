#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ac,as,bc,bs;
    cin>>ac>>as>>bc>>bs;
    if(ac==bc)ans[1]=1;
    if(as[0]==bs[0]&&as[1]==bs[1])ans[2]=1;
    else ans[2]=ans[3]=ans[4]=0;
    if(as[0]==bs[0]&&as[1]==bs[1]){
        if((as[2]<='C'&&bs[2]<='C')||(as[2]>='D'&&bs[2]>='D'))ans[3]=1;
        if(abs(as[2]-bs[2])==1&&ans[3]==1)ans[4]=1;
    }
    if(ans[1]==0)ans[2]=ans[3]=ans[4]=0;
    if(ans[2]==0)ans[3]=ans[4]=0;
    if(ans[3]==0)ans[4]=0;
    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
    return 0;
}
