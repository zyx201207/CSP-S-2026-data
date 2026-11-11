#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char w1=s1[2];
    char w2=s2[2];
    if(w1>w2)swap(w1,w2);
    bool pd=0;
    if(w1<='C'&&w2<='C')pd=1;
    if(w1>'C'&&w2>'C')pd=1;
    cout<<(c1==c2);
    cout<<(c1==c2&&p1==p2);
    cout<<(c1==c2&&p1==p2&&pd);
    cout<<(c1==c2&&p1==p2&&pd&&w2==w1+1);
    return 0;
}
