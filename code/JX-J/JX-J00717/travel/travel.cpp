#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int ss1=0,ss2=0,cc1=0,cc2=0;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    for(int i=0;i<=1;i++){
        ss1=ss1*10+s1[i]-'0';
    }
    for(int i=0;i<=1;i++){
        ss2=ss2*10+s2[i]-'0';
    }
    if(ss1==ss2){
        cout<<1;
        for(int i=0;i<=1;i++){
            cc1=cc1*10+c1[i]-'0';
        }
        for(int i=0;i<=1;i++){
            cc2=cc2*10+c2[i]-'0';
        }
        if(cc1==cc2){
            cout<<1;
            if(c1[2]>='D' && c2[2]>='D'){
                cout<<"11";
            }
            else if(c1[2]<='C' && c2[2]<='C'){
                cout<<"1";
                if(c1[2]-c2[2]==1 || c2[2]-c1[2]==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
