#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    string ans;
    int s111=(s1[0]-'0')*10+s1[1]-'0';
    int s222=(s2[0]-'0')*10+s2[1]-'0';
    if(s111==s222){
        ans=ans+"1";
        int c11=(c1[0]-'0')*10+c1[1]-'0';
        int c22=(c2[0]-'0')*10+c2[1]-'0';
        if(c11==c22){
            ans=ans+"1";
            bool xa,xb;
            if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'){
                xa=0;
            }else{
                xa=1;
            }
            if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
                xb=0;
            }else{
                xb=1;
            }
            if(xa==xb){
                cout<<"1";
                int xc=c1[2];
                int xd=c2[2];
                if(xc==70){
                    xc--;
                }
                if(xd==70){
                    xd--;
                }
                if(xc-xd==1||xc-xd==-1){

                    ans=ans+"1";
                }else{
                    ans=ans+"0";
                    return 0;
                }
            }else{
                ans=ans+"00";
                return 0;
            }
        }else{
            ans=ans+"000";
            return 0;
        }
    }else{
        ans=ans+"0000";
        return 0;
    }
    cout<<ans;
    return 0;
}
