#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1,b1;
string a2,b2;
string s1="ABC";
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<1;
            if(s1.find(a2[2])==-1&&s1.find(b2[2])==-1||s1.find(a2[2])!=-1&&s1.find(b2[2])!=-1){
                cout<<1;
                if(a2[2]=='A'&&b2[2]=='C'||a2[2]=='A'&&b2[2]=='C') cout<<0;
                else cout<<1;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
