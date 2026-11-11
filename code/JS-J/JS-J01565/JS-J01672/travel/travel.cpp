#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<=67&&s2[2]<=67)||(s1[2]>=68&&s2[2]>=68)){
                cout<<1;
                if(s1[2]+s2[2]==132){
                    cout<<"0";
                }else{
                    cout<<1;
                }


            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
