#include<bits/stdc++.h>
using namespace std;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string a=s1[0]+s1[1],b=s2[0]+s2[1];
    char c=s1[2],d=s2[2];
    if(c1==c2){
        ans+='1';
        if(a==b){
            ans+='1';
            if((c<68&&d<68)||(c>67&&d>67)){
                ans+='1';
                if(abs(c-d)==1) ans+='1';
                else ans+='0';
            }
            else ans+='00';
        }
        else ans+='000';
    }
    else ans+='0000';
    cout<<ans;
    return 0;
}
