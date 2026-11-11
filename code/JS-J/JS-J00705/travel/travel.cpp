#include<bits/stdc++.h>
using namespace std;
string Rc,Rs,Xc,Xs;
int ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>Rc>>Rs>>Xc>>Xs;
    if(Rc==Xc)ans[0]=1;
    if(ans[0]==1 &&Rs[0]==Xs[0] && Rs[1]==Xs[1])ans[1]=1;
    if(ans[1]==0){
        ans[2]=0;
        ans[3]=0;
    }
    else{
        char R=Rs[2],X=Xs[2];
        if((R<='C' && X<='C') || (R>'C' && X>'C'))ans[2]=1;
        if(R=='A' && X=='B')ans[3]=1;
        else if(R=='B' && (X=='A'|| X=='C') )ans[3]=1;
        else if(R=='C' && X=='B')ans[3]=1;
        else if(R=='D' && X=='F')ans[3]=1;
        else if(R=='F' && X=='D')ans[3]=1;
    }
    for(int i=0;i<4;i++)cout<<ans[i];
    return 0;
}
