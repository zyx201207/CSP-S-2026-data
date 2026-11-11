#include <bits/stdc++.h>
using namespace std;
//#define debug
int main(){
#ifndef debug
freopen("travel.out","w",stdout);
freopen("travel.in","r",stdin);
#endif
    int c1,c2,s1n,s2n;
    cin>>c1;
    char s1p,s2p;
    cin>>s1n>>s1p>>c2>>s2n>>s2p;
    if(c1==c2) {cout<<1;
    if(s1n==s2n) {
        cout<<1;
        bool f1=(s1p^'A')<3;
        bool f2=(s2p^'A')<3;
        if(f1==f2){
            cout<<1;
            if (!f1) cout<<1;
            else{
                int t1=(s1p^'A'),t2=(s2p^'A');
                if(s1p=='F') t1--;
                if (s2p=='F') t2--;
                if (t1-t2==1||t2-t1==1) cout<<1;
                else cout<<0;
            }
        }else cout<<0<<0;
    }else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
#ifndef debug
fclose(stdout);
fclose(stdin);
#endif
    return 0;
    }
