#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        a=s2[0]+s2[1];
        b=s4[0]+s4[1];
        if(a==b){
            cout<<1;
            a=s2[2];
            b=s4[2];
            if(a<="C"&&b<="C"&&a>="A"&&b>="A"){
                cout<<1;
                char aa=char(s2[2]);
                char bb=char(s4[2]);
                if(abs(aa-bb)==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else if(a>="D"&&a<="F"&&b>="D"&&b<="F"){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}