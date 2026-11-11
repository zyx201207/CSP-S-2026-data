#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }if(abs(s1[2]-s2[2])==1) cout<<1;
    else cout<<0;
    cout<<endl;
    return 0;
}