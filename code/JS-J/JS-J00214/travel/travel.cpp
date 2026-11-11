#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,s1,c2,s2;
char s11,s22;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    c1=(a[0]-'0')*10+a[1]-'0';
    s1=(b[0]-'0')*10+b[1]-'0';
    s11=b[2];
    c2=(c[0]-'0')*10+c[1]-'0';
    s2=(d[0]-'0')*10+d[1]-'0';
    s22=d[2];
    if(c1!=c2)cout<<"0000";
    else{
        if(s1!=s2)cout<<"1000";
        else{
            int o1,o2;
            if('A'<=s11&&s11<='C')o1=1;
            else o1=2;
            if('A'<=s22&&s22<='C')o2=1;
            else o2=2;
            if(o1!=o2)cout<<"1100";
            else{
                if(o1==2)cout<<"1111";
                else{
                    if(abs(s22-s11)==1)cout<<"1111";
                    else cout<<"1110";
                }
            }
        }
    }
    return 0;
}
