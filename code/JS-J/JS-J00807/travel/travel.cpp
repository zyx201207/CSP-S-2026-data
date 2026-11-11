#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    string ans="";
    if(a1==a2){
        ans=ans+'1';
        if(b1[0]==b2[0] && b1[1]==b2[1]){
            ans=ans+'1';
            if((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='A'&&b2[2]=='C')||(b1[2]=='B'&&b2[2]=='C')||(b1[2]=='C'&&b2[2]=='B')||(b1[2]=='C'&&b2[2]=='A')||(b1[2]=='B'&&b2[2]=='A')||(b1[2]=='D'&&b2[2]=='F')||(b1[2]=='F'&&b2[2]=='D')){
                ans=ans+'1';
                if((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='B'&&b2[2]=='C')||(b1[2]=='D'&&b2[2]=='F')||(b1[2]=='F'&&b2[2]=='D')||(b1[2]=='B'&&b2[2]=='A')||(b1[2]=='C'&&b2[2]=='B')){
                    ans=ans+'1';
                }
                else ans=ans+'0';
            }
            else ans=ans+"00";
        }

        else ans=ans+"000";

    }
    else ans=ans+"0000";


    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
