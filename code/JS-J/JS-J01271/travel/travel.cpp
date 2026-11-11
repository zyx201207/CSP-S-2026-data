#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if(s1[2]<='C' && s2[2]<='C'){
                cout<<1;
                if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1) cout<<1;
                else cout<<0;
            }
            else if(s1[2]>'C' && s2[2]>'C'){
                cout<<1;
                if(s1[2]-s2[2]==2 || s2[2]-s1[2]==2) cout<<1;
                else cout<<0;
            }
            else{
                cout<<0;
                cout<<0;
            }
        }
        else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
