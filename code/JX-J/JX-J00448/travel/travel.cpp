#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,c="",x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        c+="1";
        x=s1[0]+s1[1];
        y=s2[0]+s2[1];
        if(x==y)
        {
            c+="1";
            if(s1[2]<='C'&&s2[2]<='C')
            {
                c+="1";
                int o=abs((s2[2]-'0')-(s1[2]-'0'));
                if(o==1)
                {
                    c+="1";
                }
                else
                {
                    c+="0";
                }
            }
            else if(s1[2]>='D'&&s2[2]>='D'){
                c+="11";
            }
            else
            {
                c+="00";
            }
        }
        else
        {
            c+="000";
        }
    }
    else
    {
        c+="0000";
    }
    cout<<c;
    return 0;
}
