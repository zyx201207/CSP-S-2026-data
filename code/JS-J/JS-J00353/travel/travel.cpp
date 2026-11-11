#include<bits/stdc++.h>
using namespace std;
int ans[5],l=0;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    else{
        ans[1]=1;
    }
    if(b[0]==d[0]&&d[1]==b[1]){
        ans[2]=1;
        l=1;
    }
    if(l==1){
        if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]!='D'&&d[2]!='F'&&b[2]!='F'&&d[2]!='D')){
            ans[3]=1;
        }
        if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')){
            ans[4]=1;
        }

    }
    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
    return 0;
}
