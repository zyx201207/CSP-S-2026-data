#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a!=b)cout<<"0000";
    else{
        c=(s1[0]-'0')*10+(s1[1]-'0');
        e=s1[2];
        d=(s2[0]-'0')*10+(s2[1]-'0');
        f=s2[2];
        if(c!=d)cout<<"1000";
        else{
            if(e<='C'&&f>='D'||f<='C'&&e>='D')cout<<"1100";
            else{
                if(e=='A'&&f=='C'||f=='A'&&e=='C')cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
