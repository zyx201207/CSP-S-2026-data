#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
    }
    else{
        int a=s2[0]-'0';
        a*=10;
        a+=s2[1]-'0';
        int b=s4[0]-'0';
        b*=10;
        b+=s4[1]-'0';
        if(a!=b){
            cout<<"1000";
        }
        else{
            a=s2[2]-'A';
            b=s4[2]-'A';
            int a1=max(a,b);
            int b1=min(a,b);
            if(a1==3){
                cout<<"1100";
            }
            else if(a1==5){
                if(b1!=3){
                    cout<<"1100";
                }
                else{
                    cout<<"1111";
                }
            }
            else{
                if(b1+1!=a1){
                    cout<<"1110";
                }
                else{
                    cout<<"1111";
                }
            }
        }
    }
    return 0;
}
