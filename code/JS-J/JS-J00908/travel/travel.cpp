#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    int a=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
    int b=(int)(s4[0]-'0')*10+(int)(s4[1]-'0');
    int x=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
    int y=(int)(s3[0]-'0')*10+(int)(s3[1]-'0');
    char c=(char)s2[2];
    char d=(char)s4[2];
    if(x==y){
        cout<<"1";
        if(a==b){
            cout<<"1";
            if(!(c<='C' && d>='D') && !(c>='D' && d<='C')){
                cout<<"1";
                if(abs((int)c-(int)d)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
return 0;
}

