#include <bits/stdc++.h>

using namespace std;

string s,c,sl,cl,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>c>>sl>>cl;
    if(sl==s){
        ans=ans+"1";
        if(cl[0]==c[0]&&cl[1]==c[1]){
            ans=ans+"1";
            if((cl[2]<='C'&&c[2]<='C')||(cl[2]<='C'&&c[2]<='C')){
                ans=ans+"1";
                if(c[2]-cl[2]==-1||c[2]-cl[2]==1){
                    ans=ans+"1";
                }
                else{
                    ans=ans+"0";
                }
            }else{
                ans=ans+"00";
            }
        }
        else{
            ans=ans+"000";
        }
    }
    else{
        ans="0000";
    }
    cout<<ans;
    return 0;
}
