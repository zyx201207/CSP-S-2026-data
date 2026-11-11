#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,n1,n2,m1,m2;
int main{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;

    for(int i=1;i<=s1.size();i++){
        if(s1[i]>='0' &&s1[i]<='9') n1+=s1[i];
        else m1+=s1[i];
        if(s2[i]>='0' &&s2[i]<='9') n2+=s2[i];
        else m2+=s2[i];
    }

    if(n1==m1) cout<<1;
    else cout<<0;

    if(m1>='A' && m1<='C'){
        if(m2>='A' && m2<='C')
            cout<<1;
        else cout<<0;
    }
    else if(m1=='D' && m1=='F'){
        if(m2=='D' && m2=='F') cout<<1;
        else cout<<0;
    }
    else cout<<0;

    if(m1-1==m2 || m2-1==m1) cout<<1;
    else cout<<0;


    return 0;
}
