#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string a1,b1,a2,b2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin>>a1>>a2>>b1>>b2;
    bool t1=0;
    if(a1==b1) cout<<1,t1=1;
    else cout<<0;

    bool t2=0;
    if(a2[0]==b2[0] && a2[1]==b2[1] && t1) cout<<1,t2=1;
    else cout<<0;

    char an=a2[2],bn=b2[2];
    bool t3=0;
    if( ( ('A'<=an&&an<='C'&&'A'<=bn&&bn<='C') || \
          ('D'<=an&&an<='F'&&'D'<=bn&&bn<='F') )    && t2) 
        cout<<1,t3=1;
    else cout<<0;
    
    if((an=='A'&&bn=='B'|| \
        an=='B'&&bn=='A'|| \
        an=='B'&&bn=='C'|| \
        an=='C'&&bn=='B'|| \
        an=='D'&&bn=='F'|| \
        an=='F'&&bn=='D')    && t3)    
            cout<<1;
    else cout<<0;

    cout<<endl;

    return 0;
}
//这啥阿上来一托if