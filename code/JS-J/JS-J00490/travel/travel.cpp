#include<bits/stdc++.h>
#define int long long
#define N 100007 
using namespace std;
string n1,n2;
string s1,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1[0]==n2[0]&&n1[1]==n2[1]){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(s1[2]-'A'<=2&&s2[2]-'A'<=2){
                cout<<1;
                if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
                    cout<<1;
                }else cout<<0;
            }else if(s1[2]-'A'<=2&&s2[2]-'A'<=2){
                cout<<1;
                if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;  
}