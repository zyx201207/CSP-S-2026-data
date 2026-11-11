#include <bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a1=stoi(c1),b1=stoi(s1.substr(0,2));
    int a2=stoi(c2),b2=stoi(s2.substr(0,2));
    if (a1==a2) {
        cout<<1;
        if (b1==b2) {
            cout<<1;
            if (b1==b2 && (s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') ||
                (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')) {
                cout<<1;
                if (abs((int)s1[2]-(int)s2[2])==1 && !((s1[2]=='C' && s2[2]=='D')||(s1[2]=='D' && s2[2]=='C'))) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
