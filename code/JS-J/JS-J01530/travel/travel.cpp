#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,ans="";
    cin>>a>>b>>c>>d;
    if(a==c)
        ans=ans+"1";
    else
        ans=ans+"0";


    if(ans[0]=='1' && b[0]==d[0] && b[1]==d[1])
        ans=ans+"1";
    else
        ans=ans+"0";



    if(ans[1]=='1'){
        if((b[2]=='A' || b[2]=='B' || b[2]=='C')&&(d[2]=='A' || d[2]=='B' || d[2]=='C'))
            ans=ans+"1";
        else if((b[2]=='E' || b[2]=='F')&&(d[2]=='E' || d[2]=='F'))
            ans=ans+"1";
        else
            ans=ans+"0";
    }
    else{
        ans=ans+"0";
    }


    if(ans[2]=='1' && abs(b[2]-d[2])==1)
        ans+="1";
    else
        ans+="0";
    cout<<ans;
    return 0;
}
