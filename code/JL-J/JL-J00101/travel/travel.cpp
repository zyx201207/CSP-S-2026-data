#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c;
    c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return f*c;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<"1";
        if(s2[0]==s4[0] && s2[1]==s4[1]){
            cout<<"1";
            if(((s2[2]>='A' && s2[2]<='C') && (s4[2]>='A' && s4[2]<='C')) || ((s2[2]>='D' && s2[2]<='F') && (s4[2]>='D' && s4[2]<='F'))){
                cout<<"1";
                if(s2[2]>='A' && s2[2]<='C'){
                    if(abs(s2[2]-s4[2])==1) cout<<"1";
                    else cout<<"0";
                }
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
