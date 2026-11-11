#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,c1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s2[1]==s1[1]){
            cout<<1;
            if(s1[2]>='D'){
                if(s2[2]>='D'){
                    cout<<1;
                    if(s2[2]==s1[2]+1||s1[2]==s2[2]+1){
                        cout<<1;
                    }
                    else cout<<0;
                }
                else{
                    cout<<0<<0;
                }
            }
            else{
                if(s2[2]<'D'){
                    cout<<1;
                    if(s2[2]==s1[2]+1||s1[2]==s2[2]+1){
                        cout<<1;
                    }
                    else cout<<0;
                }
                else{
                    cout<<0<<0;
                }
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
