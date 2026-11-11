#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    string ans="";
    if(a1!=b1)ans="0000";
    else{
        ans+="1";
        int a=0,b=0;
        int aa,bb;
        for(char c:a2){
            if(c-'0'>=0&&c-'0'<=9)a=a*10+(c-'0');
            else aa=c-'A';
        }
        for(char c:b2){
            if(c-'0'>=0&&c-'0'<=9)b=b*10+(c-'0');
            else bb=c-'A';
        }
        if(a==b){
            ans+="1";
            if(aa==0||aa==2){
                if(bb==1)ans+="11";
                else{

                    if(bb<=2)ans+="1";
                    else ans+="0";
                    ans+="0";
                }
            }
            else if(aa==1){
                if(bb==0||bb==2)ans+="11";
                else {
                    ans+="10";
                }
            }
            else if(aa==3){
                if(bb==5)ans+="11";
                else ans+="10";
            }
            else {
                if(bb==3)ans+="11";
                else ans+="10";

                }
            }
        else{
            ans+="000";
        }

    }
    cout<<ans;
    return 0;
}
